/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 25/02/2024
/// @brief implements funtions of scene.hpp

#include "../Headers/Scene.hpp"
#include "../Headers/ParticleSystem.hpp"
namespace misi
{
	Scene::Scene(RenderWindow* givenWindow, b2Vec2 givenGravity, float given_scale)
	{
		window = givenWindow;
		window->setVerticalSyncEnabled(true);
		auto world = new physicWorld(givenGravity);
		windowWorld = world;
        rederer = new Renderer(*world, *window, given_scale);
        messenger = new Message_Dispacher(this);
        inputControler = new InputManager(window, this);
        inputControler->set_message_dispacher(messenger);
        collisionControler = new CollisionListener(messenger);
        world->getWorldReference()->SetContactListener(collisionControler);
        messenger->add(*this, "Scene");
        activeColision = false;
	}
	void Scene::Run()
	{
        do
        {
            timer.restart();

            

            inputControler->Run();

            messenger->execute(0);
            if (particleSystem != nullptr)
            {
                particleSystem->Update(1);
            }

            windowWorld->getWorldReference()->Step(delta_time, 8, 4);


            raiseplataform(activeColision);
            window->clear();

            rederer->Render();

            if (particleSystem != nullptr)
            {
                particleSystem->Render();
            }

            window->display();



            float elapsed = timer.getElapsedTime().asSeconds();

            if (elapsed < target_time)
            {
                sleep(seconds(target_time - elapsed));
            }

        

            delta_time = timer.getElapsedTime().asSeconds();
        } while (running);
	}

    Scene::~Scene()
    {
        delete windowWorld; 
        delete rederer;     
        delete messenger;  
        delete inputControler;
        delete collisionControler;
        delete particleSystem;
    }
    void Scene::handle(const Message& message)
    {
        std::string key;
        parameter value;
        for (const auto& entry : message.parameters) {
            key = entry.first;
            value = entry.second;
        }
        if (key == "raise Plataform")
        {
            activeColision = true;
        }
        if (key == "Stop Plataform")
        {
            activeColision = false;
        }
    }
}