/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024
/// @brief Main class

#include "../Headers/MultiShapeObject.hpp"
#include "../Headers/Scene.hpp"
#include "../Headers/Car.hpp"
#include "../Headers/Turret.hpp"
#include "../Headers/ParticleSystem.hpp"


using namespace sf;
using namespace misi;
using namespace std;


 void createModels(Scene* scene) //mover a una clase
 {
    Car* car= new Car(scene);
    car->SetCarTourge(75);
    car->SetClawTourge(75);
    BackGround* background = new BackGround(scene);
    background->SetClawTourge(75);
    scene->SetBackground(background);
 }

 void Createparticules(Scene* scene, RenderWindow* windowPtr)
 {
     ParticleSystem* EndParticles = new ParticleSystem(Vector2f(5.f, 5.f), Vector2f(.1f, .05f),
         Shapesphere, Vector2f(0.f, 0.01f), 100, 60, windowPtr, scene->getPhysicWorld());
         EndParticles->AddListener(scene);
         scene->AddParticleSystem(EndParticles);
 }


  int main()
    {
        RenderWindow window(VideoMode(1920, 700), "Practica Animación", Style::Titlebar | Style::Close, ContextSettings(32));
        RenderWindow* windowPtr = &window;
        auto mainScene = new Scene(windowPtr, b2Vec2{0.f, -10.f },100);
        createModels(mainScene);
        Createparticules(mainScene, windowPtr);
        mainScene->Run();



        
    }
