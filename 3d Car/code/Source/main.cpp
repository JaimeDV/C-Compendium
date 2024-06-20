/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 12/05/2024
/// @brief Main class


#include "../Headers/Scene.hpp"
#include "../Headers/Sphere.hpp"
#include "../Headers/MovingPlataform.hpp"
#include "../Headers/Key.hpp"
#include "../Headers/Door.hpp"
#include "../Headers/Tank.hpp"


using namespace std;
using namespace glt;
using namespace misi;



void CreateBackground(shared_ptr<Scene> mainScene)
{
    auto basePlataform = make_unique <PhysicPlane>(btVector3(0, 0, 0), 0.f,
        btVector3(0, 0, 0), 0.1f, kinematicObject, btVector3(-8, -1, 0), btVector3(6, 0.1f, 3));
    basePlataform->SetName("Base");
    mainScene->addModel(std::move(basePlataform));

    auto blockPlataform = make_unique <PhysicPlane>(btVector3(0, 0, 0), 0.f,
        btVector3(0, 0, 0), 0.1f, kinematicObject, btVector3(4, -1, 0), btVector3(2, 0.1f, 3));
    blockPlataform->SetName("blockBase");
    mainScene->addModel(std::move(blockPlataform));

}

void CreateInteractables(shared_ptr<Scene> mainScene)
{
    auto sceneDoor = make_shared <Door>(btVector3(0, 0, 0), 1.f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(-2.1f, 1.1f, 0), btVector3(0.1f, 1.f, 3));

    sceneDoor->GetModel()->SetName("Door");



    auto DoorUp = make_shared <PhysicPlane>(btVector3(0, 0, 0), 1.f,
        btVector3(0, 0, 0), 0.1f, kinematicObject, btVector3(-2.1f, 3.f, 0), btVector3(0.1f, 1, 3));

    DoorUp->SetName("DoorUp");

    sceneDoor->GetModel()->AddhidgeConection(DoorUp, btVector3(0.1f, 0.1f, 0.1f), btVector3(1.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f));
    sceneDoor->GetModel()->LockRotation();

    mainScene->addModel(std::move(sceneDoor->GetModel()));

    mainScene->addModel(std::move(DoorUp));




    //auto player = make_shared <PhysicPlane>(btVector3(0, 0, 0), 1.f,
    //    btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(-3.1f, 5, 2), btVector3(0.3f, 0.3f, 0.3f));
    //player->SetName("player");
   


    auto doorkey = make_unique <Key>(btVector3(0, 0, 0), 1.f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(-3.1f, -1, 2), btVector3(0.3f, 0.3f, 0.3f));
    doorkey->SetName("key");


    auto Car = make_shared<Tank>(btVector3(0, 0, 0), 1.f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(-10.1f, 1, 2), btVector3(1.f, 0.3f, 0.3f));
    Car->SetName("Player");

    auto wheel = make_shared<PhysicSphere>(btVector3(0, 0, 0), 1.f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(-8.1f,1, 2));
    wheel->SetName("FrontWheel");

    auto wheel2 = make_shared<PhysicSphere>(btVector3(0, 0, 0), 1.f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(-16.1f, 1, 2));
    wheel2->SetName("BackWheel");

    Car->AddhidgeConection(wheel, btVector3(0.1f, 0.1f, 0.1f), btVector3(1.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f));

    Car->AddhidgeConection(wheel2, btVector3(0.1f, 0.1f, 0.1f), btVector3(-1.0f, 0.0f, 0.0f), btVector3(1.0f, 0.0f, 0.0f));

    doorkey->AddPlayer(wheel);

   
    

    auto messenger = make_shared<Message_Dispacher>(sceneDoor); 
    messenger->add(std::move(sceneDoor), "Door");
    doorkey->AddMesenger(messenger);
    mainScene->AddMeseenger(messenger);

    mainScene->AddMainPlayer(Car);

    mainScene->AddModelListener(std::move(doorkey));//el orden lidiando con uniques importa

    mainScene->addModel(std::move(Car));
    mainScene->addModel(std::move(wheel));
    mainScene->addModel(std::move(wheel2));

    auto movingPlataform = make_unique <MovingPlataform>(btVector3(0, 0, 0), 1.f,
        btVector3(0, 0, 0), 1.f, dynamicObject, btVector3(0, -1, 0), btVector3(0.5f, 0.1f, 3));
    movingPlataform->SetName("movingPlataform");
    mainScene->addModel(std::move(movingPlataform));

    auto fallingBlock = make_unique <PhysicPlane>(btVector3(0, 0, 0), 0.1f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(4, 0, 0), btVector3(0.5f, 0.5f, 0.5f));
    fallingBlock->SetName("fallingBlock1");
    mainScene->addModel(std::move(fallingBlock));

    auto fallingBlock2 = make_unique <PhysicPlane>(btVector3(0, 0, 0), 0.1f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(4, 2, 0), btVector3(0.5f, 0.5f, 0.5f));
    fallingBlock2->SetName("fallingBlock2");
    mainScene->addModel(std::move(fallingBlock2));

    auto fallingBlock3 = make_unique <PhysicPlane>(btVector3(0, 0, 0), 0.1f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(4, 2, 2), btVector3(0.5f, 0.5f, 0.5f));
    fallingBlock3->SetName("fallingBlock3");
    mainScene->addModel(std::move(fallingBlock3));

    auto fallingBlock4 = make_unique <PhysicPlane>(btVector3(0, 0, 0), 0.1f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(4, 2, -2), btVector3(0.5f, 0.5f, 0.5f));
    fallingBlock4->SetName("fallingBlock4");
    mainScene->addModel(std::move(fallingBlock4));


}


void CreateScene()
{
    auto scene = make_shared < Scene>(1366, 768);


    CreateBackground(scene);

    CreateInteractables(scene);

    auto particles = make_shared <ParticleSystem>(btVector3(0, 0, 0), 0.1f,
        btVector3(0, 0, 0), 0.1f, dynamicObject, btVector3(6, -1, 0), btVector3(1, 1, 1), btVector3(0.1f, 0.8f, 0.1f), 4, scene, 6,
        12);

    scene->AddParticleSystem(particles);

    auto inputs = make_shared<InputManager>();

    auto messenger = make_shared<Message_Dispacher>(scene);
    messenger->add(scene, "Scene");

    //key->add(door, "Door");

    inputs->set_message_dispacher(messenger);

    scene->AddInputManager(inputs);

    scene->Render();
}


int main()
{

    CreateScene();

}
