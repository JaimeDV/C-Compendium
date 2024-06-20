/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024

#include <vector>
#include "Particle.hpp"
#pragma once
namespace misi
{

    class PhysicSphere;
    class Scene;

    /// @brief Pool that holds all the particles, active and inactive
    class ParticlePool
    {
        vector<shared_ptr<Particle>> activeParticles; // Vector holding active particles
        vector<shared_ptr<Particle>> inActiveParticles; // Vector holding inactive particles
        unsigned int particleAmount; // Number of particles in the pool

        /// @brief Initializes the inactive particle list
        void InstantiatePool(btVector3 given_rotation, float given_mass,
            btVector3 given_inertia, float restitution, ObjectType given_type, btVector3 given_origin,
            btVector3 given_size, btVector3 given_velocity, float given_lifeSpam, shared_ptr<Scene> given_world, int particleAmount);

    public:

        /// @brief Constructor for ParticlePool
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
        ParticlePool(btVector3 given_rotation, float given_mass,
            btVector3 given_inertia, float restitution, ObjectType given_type, btVector3 given_origin,
            btVector3 given_size, btVector3 given_velocity, float given_lifeSpam, shared_ptr<Scene> given_world, int particleAmount)
        {
            InstantiatePool(given_rotation, given_mass, given_inertia, restitution, given_type, given_origin,
                given_size, given_velocity, given_lifeSpam, given_world, particleAmount);
        }

        /// @brief Removes the particle inside the active list at the given index and adds it to the inactive list
        /// @param index Position of the particle to deactivate
        void killParticle(int index);

        /// @brief Removes a particle from the inactive list and adds it to the active list, does nothing due to errors with set transform
        void ReviveParticle();

        /// @brief Gets the vector of active particles
        /// @return Vector of active particles
        vector<shared_ptr<Particle>> GetActive()
        {
            return activeParticles;
        }

        /// @brief Gets the vector of inactive particles
        /// @return Vector of inactive particles
        vector<shared_ptr<Particle>> GetInActive()
        {
            return inActiveParticles;
        }

    };

}