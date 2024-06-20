/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 25/02/2024

#pragma once
#include "box2d/box2d.h"
#include "Windows.h"
#include "SFML/Graphics.hpp"
#include "World.hpp"
#include "Render.hpp"
#include "Message.hpp"
#include "InputManager.hpp"
#include "Collision.hpp"
#include "Turret.hpp"


using namespace sf;

namespace misi
{
    class ParticleSystem;

    /// @brief Class that houses the physical word & the window/ render kernel
	class Scene:public Message_Listener
	{
        const float physics_to_graphics_scale = 100.f;     

        const float target_fps = 60.f;                   
        const float target_time = 1.f / target_fps;        

        float delta_time = target_time;                   
        bool  running = true;

        Clock timer;

        RenderWindow* window;

        physicWorld* windowWorld;

        Renderer* rederer;

        Message_Dispacher* messenger;

        InputManager* inputControler;

        CollisionListener* collisionControler;

        ParticleSystem* particleSystem=nullptr;

        BackGround* background;// scuffed solution, should be replaced  by a polley fixture when i have time

        bool activeColision;
        virtual void handle(const Message& message) override;
        ~Scene();

        public:
            Scene(RenderWindow* givenWindow, b2Vec2 gravity, float scale);
            void Run();
            
            inline physicWorld* getPhysicWorld()
            {
                return windowWorld;
            }
            inline void AddParticleSystem(ParticleSystem * system )
            {
                particleSystem = system;//should change to a list 
            }

            inline Message_Dispacher* getMessenger()
            {
                return messenger;
            }
            inline CollisionListener* getCollisionController()
            {
                return collisionControler;
            }
            inline void SetBackground(BackGround* given_background)
            {
                background = given_background;
            }

            inline void exit()
            {
                running = false;
            }
            /// @brief event that triggers when the car hits the right limit
            inline void raiseplataform(bool active)
            {
                if (active)
                {
                    background->raisePlataform(0.005f, 7);
                }
            }
	};
}
