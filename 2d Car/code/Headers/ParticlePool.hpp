/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024

#include <vector>
#include "Particle.hpp"
#pragma once
namespace misi
{
    /// @brief Pool that holds all the particles, active and inactinve 
    class ParticlePool
    {
        vector<Particle *> activeParticles;
        vector<Particle *> inActiveParticles;
        unsigned int particleAmount;
        /// @brief initiates the inactive particle list 
        void InstantiatePool(unsigned int particleAmount, Vector2f given_position, Vector2f given_size,
            shapeType given_shape, Vector2f given_velocity, float given_lifeSpam, physicWorld* given_world);
    public:

        ParticlePool(unsigned int particleAmount, Vector2f given_position, Vector2f given_size,
            shapeType given_shape, Vector2f given_velocity, float given_lifeSpam, physicWorld* given_world)
        {
            InstantiatePool(particleAmount,  given_position,  given_size,
                 given_shape,  given_velocity,  given_lifeSpam, given_world);
        }
        /// @brief removes the particle inside the active list at the given index and adds it to the inactive list
        /// @param index position of the particle to kill
        void killParticle( int index);

        /// @brief removes a particle from the inactive list and adds it to the active list
        void ReviveParticle();

        vector<Particle*> GetActive()
        {
            return activeParticles;
        }

        vector<Particle*> GetInActive()
        {
            return inActiveParticles;
        }

    };

}