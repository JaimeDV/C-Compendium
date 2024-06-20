/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 20/04/2024
/// @brief class contains multiple meshses and acts as a wrapper for then 
#pragma once
#include "Mesh.hpp"
namespace misi
{
	class Model: public Node        
	{
	     
		private:
		vector<Mesh *> meshes;//the amount of separated meshes that compose a model.
		const std::string modelPath; //the path to the obj file containing the model

		Color_Buffer & color_buffer;//reference to the color buffer, that stores the vertex info
		Rasterizer< Color_Buffer >& rasterizer;//reference to the rasterizer, that handles drawing the colorbuffer info to pixels
		unsigned width;//Width of the viewport
		unsigned height;//height of the viewport
        float rotationSpeed=0;//speed at whitc the model rotates around the y axis 


		public:

            ~Model()
            {
                for (Mesh* mesh : meshes)
                {
                    delete mesh;
                }
            }

			Model(std::string modelPath, unsigned width, unsigned height, Color_Buffer& color_buffer,
			Rasterizer< Color_Buffer >& rasterizer);

			Model(std::string modelPath, unsigned width, unsigned height, float angle, float scale,
				math::Vector3f position, Color_Buffer& color_buffer,Rasterizer< Color_Buffer >& rasterizer);

			/// @brief Reads the model at the given path & generates the apropiate meshes in the process
			void ReadModel();


            /// @brief Sets the rotation speed of the model
            /// @param value The rotation speed value.
            void SetRotationSpeed(float value)
            {
                rotationSpeed = value;
            }

            /// @brief passes the camera reference to the meshes
            /// @param camera A pointer to the camera to be added.
            void AddCamera(Camera* camera)
            {
                for (auto modelPtr : meshes)
                {
                    modelPtr->AddCamera(camera);
                }
            }
            ///@brief calls the render funtion of all meshes
			void Render();

            ///@brief calls the update of all meshes
			void Update();
	};
}