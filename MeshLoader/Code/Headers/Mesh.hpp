/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 20/04/2024
/// @brief base class that handles triangle mesh data 
#pragma once

#include <assimp/mesh.h>
#include "TypeDef.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>
#include "Camera.hpp"
using namespace glm;
namespace misi
{
	class Mesh:public Node
	{
		

		private:
			aiMesh* meshData;
			Vertex_Buffer original_vertices; //original vertex array of the obj model without any transformation applied
			Index_Buffer original_indices;//vertex Indice indicading how the model vertices should join
			Vertex_Colors original_colors;//Array or vertices contain the individual vertex color
			Vertex_Buffer transformed_vertices;//Obj vertices with the corresponding space transform
			vector< Point4i > display_vertices;//Obj vertices with the corresponding camera transform
            Camera* mainCamera;//reference to the scene Camera


			float rotationSpeed=0; //the speed at witch the model rotates around the y axis.
			int width;//Width of the viewport
			int height;//height of the viewport

			float fatherAngle;//Rotation information of the father node
			float fatherScale;//Scale infromation of the father node
			math::Vector3f fatherPosition;//position information of the fatherPosition
		
			Color_Buffer& color_buffer;//reference to the color buffer, that stores the vertex info
			Rasterizer< Color_Buffer >& rasterizer;//reference to the rasterizer, that handles drawing the colorbuffer info to pixels

			///@brief funtion that aplies backface culling to the mesh
			bool  is_frontface(const Vertex* const projected_vertices, const int* const indices);

			///@brief funtion that returns a random number between 0-1 
			float rand_clamp() { return float(rand() & 0xff) * 0.0039215f; }

			/// @brief using the Sutherland-Hodgman algorithm clips the triangles in scene based on their position to the window position 
			/// @param vertices pointer to the vertices list of the vertices to be cliped
			/// @param v1 index of the first vertex to clip
			/// @param v2 index of the second vertex to clip
			/// @param v3 index of the third vertex to clip
			/// @param clipped_vertices pointer to the list of vertices cliped by the algorithm
			/// @returns amount of vertices cliped in the process 
			int ClipTriangles(Point4i* vertices, int v1, int v2, int v3, Point4i* clipped_vertices);

			/// @brief calculates if the given point P is contianed in plane made by V and vertex and by extensión is vertex is in the plane
			/// @param vertex vertex to coompare
			/// @param p point to compare 
			/// @param v normal vector used to define the plane		
			/// @returns distance to the given plane if negative is outside  
			float CalculateSide(const Point4i& vertex, const vec3& p, const vec3& v);

		public:

            ~Mesh()
            {
                delete meshData;
                delete mainCamera;
                original_vertices.clear();
                original_indices.clear();
                original_colors.clear();
                transformed_vertices.clear();
            }

			Mesh(aiMesh* given_mesh, int width,int height, Color_Buffer& color_buffer,
				Rasterizer< Color_Buffer >& rasterizer);

			void LoadMesh();///@brief Reads the given aimeshs and generates vertex from then
			void Update();///@brief Updates vertex position 
			void Render();///@brief transforms the vertex data to window pixels

			/// @brief Sets the mesh transforms using it's father transform
			/// @given_fatherAngle father rotation transform info
			/// @given_fatherScale father scale transform info
			/// @given_fatherPosition v father position transform info
			void SetTransformation(float given_fatherAngle, float given_fatherScale, math::Vector3f given_fatherPosition)
			{
				fatherAngle = given_fatherAngle;
				fatherScale = given_fatherScale;
				fatherPosition = given_fatherPosition;
			}

			/// @brief Sets the speed at witch the mesh rotates around y
			/// @given_rotation father rotation transform info
			void SetRotationSpeed(float given_rotation)
			{
				rotationSpeed = given_rotation;
			}

			/// @brief asigns a pointer to the scene camera 
			/// @camera father rotation transform info
            void AddCamera(Camera * camera)
            {
                mainCamera = camera;
            }

	};
}
