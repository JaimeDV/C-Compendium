/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 16/04/2024implements scene.hpp funtions


#include "../Headers/Scene.hpp"
namespace misi
{
	void Scene::Run()
	{
        window->setVerticalSyncEnabled(true);

        for (auto modelPtr : models)
        {
            modelPtr->ReadModel();
        }

        std::cin.get();
        bool running = true;

        AddCamera();
        do
        {
            // Process window events:

            Event event;

            while (window->pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    running = false;
                }
            }

            Update();
            MainCamera->Update();
            Render();

            /*window->clear();*/

            window->display();

        } while (running);

      
	}

    void Scene::Render()
    {

        for (auto modelPtr : models)
        {
            modelPtr->Render();
        }
        rasterizer.clear();
    }

    void Scene::Update()
    {
        for (auto modelPtr : models)
        {
            modelPtr->Update();
        }
    }

    void Scene::AddCamera()
    {
        for (auto modelPtr : models)
        {
            modelPtr->AddCamera(MainCamera);
        }
    }
}