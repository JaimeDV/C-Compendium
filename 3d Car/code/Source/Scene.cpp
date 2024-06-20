/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 25/02/2024
/// @brief implements funtions of scene.hpp

#include "../Headers/Scene.hpp"
#include "../Headers/ColisionChecker.hpp"
#include "../Headers/InputManager.hpp"
#include "../Headers/Tank.hpp"
namespace misi
{
   

    Scene::Scene(unsigned width, unsigned heigh): collisionDispatcher(&collisionConfiguration), worldReference( &collisionDispatcher, &overlappingPairCache,
            &constraintSolver, &collisionConfiguration)
    {

        InstantiateWindow(width, heigh);

        renderScene=CreateScene();

        ConfigureScene(*renderScene);

        ResetViewport(*window, *renderScene);

        worldReference.setGravity(btVector3(0, -10, 0));

        glClearColor(0.f, 0.3f, 0.f, 1.f);

        colisionManager = make_shared <ColisionChecker>(worldReference);

        MoveCamera(*renderScene, Vector3(-10.f, 0.f, 0.f));

    }

    void Scene::addModel(shared_ptr< PhysicBody > newModel)
    {
        if (newModel->GetHidges().size()>=1)
        {
            for (const auto& hindge : newModel->GetHidges())
            {
                worldReference.addConstraint(hindge.get());
            }

           
        }
        worldReference.addRigidBody(newModel->Getbody());
        renderScene->add(newModel->GetName(), newModel->GetModel());
        modelList.push_back(newModel);
    }

    shared_ptr< Render_Node > Scene::CreateScene()
    {
        // Se crean los elementos (nodos) y la escena a la que se añadirán:

        shared_ptr< Render_Node > scene(new Render_Node);
        shared_ptr< Camera      > camera(new Camera(20.f, 1.f, 50.f, 1.f));
        shared_ptr< Light       > light(new Light);

       
        // Se añaden los nodos a la escena:
        scene->add("camera", camera);
        scene->add("light", light);

        return scene;
    }

    void Scene::ConfigureScene(Render_Node& scene)
    {
        scene["light"]->translate(glt::Vector3(10.f, 10.f, 10.f));
        scene["camera"]->translate(glt::Vector3(0.f, 0.f, 5.f));
    }

    void Scene::ResetViewport(const sf::Window& window, Render_Node& scene)
    {
        GLsizei width = GLsizei(window.getSize().x);
        GLsizei height = GLsizei(window.getSize().y);

        scene.get_active_camera()->set_aspect_ratio(float(width) / height);

        glViewport(0, 0, width, height);
    }

    void Scene::InstantiateWindow(int width, int heigh) 
    {
        window = make_shared<sf::Window>
            (
                sf::VideoMode(width, heigh),
                "Animation practice II",
                sf::Style::Default,
                sf::ContextSettings(24, 0, 0, 3, 2, sf::ContextSettings::Core)
            );

        if (!glt::initialize_opengl_extensions())
        {
            exit(-1);
        }

        window->setVerticalSyncEnabled(true);
    }

    void Scene::Render()
    {
        bool running = true;
        do
        {
            // Read the user input:

            sf::Event event;

            while (window->pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                    {
                        running = false;
                        break;
                    }

                    case sf::Event::Resized:
                    {
                        ResetViewport(*window, *renderScene);
                        break;
                    }
                    case sf::Event::KeyPressed:
                    {
                        inputManager->handleKeyPress(event.key.code);
                        break;
                    }
                }
                
            }

            inputManager->get_message_dispacher()->execute(0);
            for (const auto& messengers : messagers)
            {
                messengers->execute(0);
            }


            if (particleSystem != nullptr)
            {
                particleSystem->Update(1);
            }

            // Perform the simulation:

            worldReference.stepSimulation(1.f / 60.f);

            // Apply the physics transform to the graphics model:

            colisionManager->CheckColisions();

            for (const auto& model : modelList) {

                btTransform physics_transform;
                glm::mat4 graphics_transform;
                model->ModelAction();
                model->Getbody()->getMotionState()->getWorldTransform(physics_transform);
                physics_transform.getOpenGLMatrix(glm::value_ptr(graphics_transform));
                Node* newModel = renderScene->get(model->GetName());
                newModel->set_transformation(graphics_transform);
                

                if (IsPhysicSphere(model))
                {
                    newModel->scale(1.f / 0.45f); //sphere have a bug that forces this scale
                }
                else
                {
                    newModel->scale(model->GetScale().x(), model->GetScale().y(), model->GetScale().z());
                }

               
            }

            // Render the scene:

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            renderScene->render();

            window->display();


        } while (running);

        for (const auto& model : modelList) {
            RemoveModel(model);
        }

    }

    void Scene::RemoveModel(shared_ptr<PhysicBody> model) {

        worldReference.removeRigidBody(model->Getbody());

        model->~PhysicBody();
    }

    void Scene::MoveCamera(Render_Node& scene, glt::Vector3 direction)
    {
        scene["camera"]->translate(direction);
    }

    void Scene::handle(const Message& message)
    {
        std::string key;
        parameter value;
        for (const auto& entry : message.parameters) {
            key = entry.first;
            value = entry.second;
        }
        if (key == "A")
        {
            MoveCamera(*renderScene, glt::Vector3(-sensitivity, 0.f, 0));
            mainPlayer->SetMoveSpeed(btVector3(-sensitivity, 0.f, 0));
        }
        if (key == "D")
        {
            MoveCamera(*renderScene, glt::Vector3(sensitivity, 0.f, 0));
            mainPlayer->SetMoveSpeed(btVector3(sensitivity, 0.f, 0));
        }
        if (key == "W")
        {
            MoveCamera(*renderScene, glt::Vector3(0.f, sensitivity,0.f));
            mainPlayer->SetMoveSpeed(btVector3(0, 0,sensitivity));
        }
        if (key == "S")
        {
            MoveCamera(*renderScene, glt::Vector3(0.f, -sensitivity, 0.f));
            mainPlayer->SetMoveSpeed(btVector3(0, 0, -sensitivity));
        }
        if (key == "E")
        {
            MoveCamera(*renderScene, glt::Vector3(0.f, 0.f, -sensitivity));
        }
        if (key == "Q")
        {
            MoveCamera(*renderScene, glt::Vector3(0.f, 0.f, sensitivity));
        }
    }

    void Scene::AddModelListener(shared_ptr< PhysicBody > listener)
    {
        addModel(listener);
        colisionManager->AddListener(listener);
    }

    bool Scene::IsPhysicSphere(const std::shared_ptr<PhysicBody>& obj) {

        if (obj->Getvolume() == Sphere)
        {
            return true;
        }
        return false;
    }
}
