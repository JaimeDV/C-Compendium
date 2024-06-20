/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024

#pragma once
#include "ParticleRenderer.hpp"
#include "ParticleUpdater.hpp"
namespace misi
{
    /// @brief Master class that encapsulates the behaviour of all particle components 
    /// Due to render issues is now using box2d most feature don't work 
    class ParticleSystem
    {
        ParticleRenderer* renderer=nullptr;
        ParticleUpdater* updater = nullptr;
        ParticlePool* pool = nullptr;

    public:
        ParticleSystem(Vector2f particle_position, Vector2f particle_size,
            shapeType given_shape,Vector2f particle_velocity, float particle_lifeSpam,
            unsigned int particleFlow, RenderWindow* window, physicWorld* given_world);

        /// @brief calls the update funtion of the updater
        /// @param t times the funtion is called per tick
        void Update(float t) 
        {
            updater->Update(t);
        }
        //unusued
        void Render()
        {
            renderer->Render();
        }

        void AddListener(Scene* givenScene)
        {
            updater->SetListener( givenScene);
        }
        ~ParticleSystem()
        {
            delete renderer;
            delete updater;
            delete pool;
        }
    };
}