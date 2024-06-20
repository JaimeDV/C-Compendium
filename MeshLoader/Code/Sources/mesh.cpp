
#include "../Headers/Mesh.hpp"
namespace misi
{
	Mesh::Mesh(aiMesh* given_mesh, int given_width, int given_height, Color_Buffer& given_color_buffer,
    Rasterizer< Color_Buffer >& given_rasterizer) :meshData(given_mesh),
        width(given_width), height(given_height),color_buffer(given_color_buffer), rasterizer(given_rasterizer)
	{
		LoadMesh();
	}
	void Mesh::LoadMesh()
	{
        size_t number_of_vertices = meshData->mNumVertices;

        original_vertices.resize(number_of_vertices);

        for (size_t index = 0; index < number_of_vertices; index++)
        {
            auto& vertex = meshData->mVertices[index];

            original_vertices[index] = Vertex(vertex.x, -vertex.y, vertex.z, 1.f);
        }

        transformed_vertices.resize(number_of_vertices);
        display_vertices.resize(number_of_vertices);

        original_colors.resize(number_of_vertices);

        for (size_t index = 0; index < number_of_vertices; index++)
        {
            original_colors[index].set(rand_clamp(), 1.0f, 1.0f);
        }

     

        size_t number_of_triangles = meshData->mNumFaces;

        original_indices.resize(number_of_triangles * 3);

        Index_Buffer::iterator indices_iterator = original_indices.begin();

        for (size_t index = 0; index < number_of_triangles; index++)
        {
            auto& face = meshData->mFaces[index];

            assert(face.mNumIndices == 3);        

            auto indices = face.mIndices;

            *indices_iterator++ = int(indices[0]);
            *indices_iterator++ = int(indices[1]);
            *indices_iterator++ = int(indices[2]);
        }
	}
	void Mesh::Render()
	{
        
        Matrix44 identity(1);
        Matrix44 scaling = scale(identity, float(width / 2), float(height / 2), 100000000.f);
        Matrix44 translation = translate(identity, Vector3f{ float(width / 2), float(height / 2), 0.f });
        Matrix44 transformation = translation * scaling; 

        for (size_t index = 0, number_of_vertices = transformed_vertices.size(); index < number_of_vertices; index++)
        {
            display_vertices[index] = Point4i(transformation * transformed_vertices[index]);
        }

        

        for (int* indices = original_indices.data(), *end = indices + original_indices.size(); indices < end; indices += 3)
        {

            if (is_frontface(transformed_vertices.data(), indices))
            {
                

                rasterizer.set_color(original_colors[*indices]);

              
                Point4i clipped_vertices[10];
                static const int clipped_indices[]{ 0,1,2,3,4 };
                int clipped_vertices_count = ClipTriangles(display_vertices.data(), indices[0], indices[1], indices[2], clipped_vertices);

                if (clipped_vertices_count >= 3)
                {
                    rasterizer.fill_convex_polygon_z_buffer(clipped_vertices, clipped_indices, clipped_indices+ clipped_vertices_count);
                }
               
            }
        }

        color_buffer.blit_to_window();
	}
	void Mesh::Update()
	{
      

        fatherAngle += rotationSpeed;
        GetFather()->SetAngle(fatherAngle);
      
        // Creación de la matriz de transformación unificada:

        Matrix44 transformation = mainCamera->GetProjection() * mainCamera->GetInverse()* GetFather()->GetTransform(); ///NEcesito aqui la inversa del 
        
        //transform de camara,  Matrix44 transformation = projection * camera inverse *translation * rotation_y * scaling; 
        //proyection deberia estar en camara 

        // Se transforman todos los vértices usando la matriz de transformación resultante:

        for (size_t index = 0, number_of_vertices = original_vertices.size(); index < number_of_vertices; index++)
        {
            // Se multiplican todos los vértices originales con la matriz de transformación y
            // se guarda el resultado en otro vertex buffer:

            Vertex& vertex = transformed_vertices[index] = transformation * original_vertices[index];

            // La matriz de proyección en perspectiva hace que el último componente del vector
            // transformado no tenga valor 1.0, por lo que hay que normalizarlo dividiendo:

            float divisor = 1.f / vertex.w;

            vertex.x *= divisor;
            vertex.y *= divisor;
            vertex.z *= divisor;
            vertex.w = 1.f;
        }
	}
	bool Mesh::is_frontface(const Vertex* const projected_vertices, const int* const indices)
	{
		const Vertex& v0 = projected_vertices[indices[0]];
		const Vertex& v1 = projected_vertices[indices[1]];
		const Vertex& v2 = projected_vertices[indices[2]];

		// Se asumen coordenadas proyectadas y polígonos definidos en sentido horario.
		// Se comprueba a qué lado de la línea que pasa por v0 y v1 queda el punto v2:

		return ((v1[0] - v0[0]) * (v2[1] - v0[1]) - (v2[0] - v0[0]) * (v1[1] - v0[1]) < 0.f);
	}

    //if a vertex is outisde removes it. It's not a full Sutherland-Hodgman implementation
    int Mesh::ClipTriangles(Point4i* vertices, int v1, int v2, int v3, Point4i* clipped_vertices)
    {


        const Point4i& vertex_a = vertices[v1];
        const Point4i& vertex_b = vertices[v2];
        const Point4i& vertex_c = vertices[v3];

        #pragma region leftPlane
        const vec3 left_plane_p{ 0.0f, 0.0f, 0.0f };
        const vec3 left_plane_v{ 1.0f, 0.0f, 0.0f };

        float vertex_a_left_side = CalculateSide(vertex_a, left_plane_p, left_plane_v);
        float vertex_b_left_side = CalculateSide(vertex_b, left_plane_p, left_plane_v);
        float vertex_c_left_side = CalculateSide(vertex_c, left_plane_p, left_plane_v);
        #pragma endregion

        #pragma region rightPlane

        const vec3 right_plane_p{ width, 0.0f, 0.0f };
        const vec3 right_plane_v{ -width, 0.0f, 0.0f };

        float vertex_a_right_side = CalculateSide(vertex_a, right_plane_p, right_plane_v);
        float vertex_b_right_side = CalculateSide(vertex_b, right_plane_p, right_plane_v);
        float vertex_c_right_side = CalculateSide(vertex_c, right_plane_p, right_plane_v);
        #pragma endregion

        #pragma region topPlane
        const vec3 top_plane_p{ 0.0f, 0.0f, 0.0f };
        const vec3 top_plane_v{ 0.0f, 1.0f, 0.0f };

        float vertex_a_top_side = CalculateSide(vertex_a, top_plane_p, top_plane_v);
        float vertex_b_top_side = CalculateSide(vertex_b, top_plane_p, top_plane_v);
        float vertex_c_top_side = CalculateSide(vertex_c, top_plane_p, top_plane_v);
        #pragma endregion

        #pragma region bottonPlane
        const vec3 bottom_plane_p{ 0.0f, height, 0.0f };
        const vec3 bottom_plane_v{ 0.0f, -height, 0.0f };

        float vertex_a_bottom_side = CalculateSide(vertex_a, bottom_plane_p, bottom_plane_v);
        float vertex_b_bottom_side = CalculateSide(vertex_b, bottom_plane_p, bottom_plane_v);
        float vertex_c_bottom_side = CalculateSide(vertex_c, bottom_plane_p, bottom_plane_v);
        #pragma endregion

        #pragma region nearPlane
        const vec3 near_plane_p{ 0.0f, 0.0f, 80000000 }; // Define near plane, hardcoded at the moment
        const vec3 near_plane_v{ 0.0f, 0.0f, 1.0f };

        float vertex_a_near_side = CalculateSide(vertex_a, near_plane_p, near_plane_v);
        float vertex_b_near_side = CalculateSide(vertex_b, near_plane_p, near_plane_v);
        float vertex_c_near_side = CalculateSide(vertex_c, near_plane_p, near_plane_v);
        #pragma endregion

        // Initialize the output indices
        int clipped_vertices_count = 0;

        if (vertex_a_left_side >= 0 && vertex_b_left_side >= 0 && vertex_c_left_side >= 0 &&
            vertex_a_right_side >= 0 && vertex_b_right_side >= 0 && vertex_c_right_side >= 0 &&
            vertex_a_top_side >= 0 && vertex_b_top_side >= 0 && vertex_c_top_side >= 0 &&
            vertex_a_bottom_side >= 0 && vertex_b_bottom_side >= 0 && vertex_c_bottom_side >= 0 &&
            vertex_a_near_side >= 0 && vertex_b_near_side >= 0 && vertex_c_near_side >= 0)
        {
            // All vertices are inside all clipping planes, no clipping needed
            clipped_vertices[clipped_vertices_count++] = vertex_a;
            clipped_vertices[clipped_vertices_count++] = vertex_b;
            clipped_vertices[clipped_vertices_count++] = vertex_c;
        }
        return clipped_vertices_count;
    
    }

    float Mesh::CalculateSide(const Point4i& vertex, const vec3& p, const vec3& v)
    {
        vec3 diff = vec3(vertex.x, vertex.y, vertex.z) - p;
        float side = dot(diff, v);
        return side;
    }

   

}
