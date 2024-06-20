/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 16/04/2024
/// @brief Central Scene & kernel Control

#pragma once

#include <iostream>
#include <functional>
#include "SFML/Graphics.hpp"
#include "model.hpp"
using namespace sf;

namespace misi
{
	class Scene
	{
		RenderWindow* window; //pointer to the sfml window that display the scene

		Color_Buffer color_buffer;//color buffer, that stores the vertex info
		Rasterizer< Color_Buffer > rasterizer;//reference to the rasterizer, that handles drawing the colorbuffer info to pixels
		vector<Model*> models;//list of all the models contain in the scene
        Camera* MainCamera;//reference to the Main camera
		
		~Scene()
		{
            for (Model* model : models)
            {
                delete model;
            }
            models.clear();
            delete MainCamera;
			delete window;
		}

		public:

			Scene(unsigned int width, unsigned int height, float given_sensitivity):color_buffer(width, height), rasterizer(color_buffer)
			{
				window = new RenderWindow(VideoMode(width, height), "GraficExamples", 
					sf::Style::Default, ContextSettings(24));
                MainCamera = new Camera(given_sensitivity, 20, 1, 15, width, height);
			}

			/// @brief Adds a model to the scene 
			/// @param new_model reference to the new model
			void AddModel(Model * new_model)
			{
				models.push_back(new_model);
			}

			/// @brief Gets the Rasterizer 
			/// @return A reference to the Rasterizer object
			Rasterizer< Color_Buffer >& GetRasterizer()
			{
				return rasterizer;
			}

			/// @brief Gets the Color_Buffer 
			/// @return A reference to the Color_Buffer object
			Color_Buffer & GetColorBuffer()
			{
				return color_buffer;
			}
			///@brief calls the render of all it's model
			void Render();

			///@brief calls the update of all it's model
			void Update();

			///@brief adds the camera to all the models
            void AddCamera();

			///@brief starts the main kernel
			void Run();


	};
}