/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024

#pragma once
#include "ParticleUpdater.hpp"
namespace misi
{
    /// @brief Master class that encapsulates the behavior of all particle components
    /// Due to render bugs acts as a smoke cloud rather than a conventional particle system shower
    class ParticleSystem
    {
        shared_ptr<ParticleUpdater> updater = nullptr; // Pointer to the particle updater
        shared_ptr<ParticlePool> pool = nullptr; // Pointer to the particle pool

    public:
        /// @brief Constructor for ParticleSystem
        /// @param given_rotation The initial rotation of the particles
        /// @param given_mass The mass of the particles
        /// @param given_inertia The inertia of the particles
        /// @param restitution The restitution value of the particles
        /// @param given_type The type of the particles
        /// @param given_origin The initial origin of the particles
        /// @param given_size The size of the particles
        /// @param given_velocity The initial velocity of the particles
        /// @param given_lifeSpam The lifespan of the particles
        /// @param given_world The scene where the particles exist
        /// @param particleAmount The number of particles in the pool
        /// @param particleFlow The flow rate of particles
        ParticleSystem(btVector3 given_rotation, float given_mass,
            btVector3 given_inertia, float restitution, ObjectType given_type, btVector3 given_origin,
            btVector3 given_size, btVector3 given_velocity, float given_lifeSpam, shared_ptr<Scene> given_world, int particleAmount,
            unsigned int particleFlow);

        /// @brief Calls the update function of the updater
        /// @param t Times the function is called per tick
        void Update(float t)
        {
            updater->Update(t);
        }

        /// @brief Adds a listener to the particle updater
        /// @param givenScene The scene to be added as a listener
        void AddListener(shared_ptr<Scene> givenScene)
        {
            updater->SetListener(givenScene);
        }

    };
}