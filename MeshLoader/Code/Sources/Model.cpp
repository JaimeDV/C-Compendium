
#include "../Headers/model.hpp"
namespace misi
{
	Model::Model(std::string given_modelPath, unsigned given_width, unsigned given_height, Color_Buffer& given_color_buffer,
		Rasterizer< Color_Buffer >& given_rasterizer):width(given_width),
		height(given_height), modelPath(given_modelPath), color_buffer(given_color_buffer),rasterizer(given_rasterizer)
	{
        SetMatrix();
		//ReadModel();
	}

	Model::Model(std::string given_modelPath, unsigned given_width, unsigned given_height, float given_angle,
		float given_scale, Vector3f given_position, Color_Buffer& given_color_buffer,
		Rasterizer< Color_Buffer >& given_rasterizer) :width(given_width),
		height(given_height), modelPath(given_modelPath),color_buffer(given_color_buffer), rasterizer(given_rasterizer)
	{
        SetAngle(given_angle);
        SetScale(given_scale);
        SetPosition(given_position);
        SetMatrix();
	/*	ReadModel();*/
	}

	void Model::ReadModel()
	{
		Assimp::Importer importer;

		const char* pathPointer = modelPath.c_str();

		auto scene = importer.ReadFile
		(
			pathPointer,
			aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType
		);

		// Si scene es un puntero nulo significa que el archivo no se pudo cargar con éxito:

		if (scene && scene->mNumMeshes > 0)
		{
            for (unsigned x = 0; x < scene->mNumMeshes; x++)
			{
				auto mesh = scene->mMeshes[x];
				auto sceneMesh =new Mesh(mesh, width, height, color_buffer, rasterizer);
				sceneMesh->SetTransformation(GetAngle(), GetScale(), GetPosition());
                sceneMesh->SetRotationSpeed(rotationSpeed);
                
                sceneMesh->SetFather(this);
				meshes.push_back(sceneMesh);
			}
			
		}
	}



	void Model::Render()
	{
		for (auto meshPtr : meshes)
		{
			meshPtr->Render();
		}
		//rasterizer.clear();
	}

	void Model::Update()
	{
		for (auto meshPtr : meshes)
		{
			meshPtr->Update();
		}
	}
}