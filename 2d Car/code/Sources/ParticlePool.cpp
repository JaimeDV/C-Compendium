/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024
/// @brief implements particle pool hpp clases 

#include "../Headers/ParticlePool.hpp"
namespace misi
{
    void ParticlePool::InstantiatePool(unsigned int given_particleAmount, Vector2f given_position,
        Vector2f given_size, shapeType given_shape, Vector2f given_velocity, float given_lifeSpam, physicWorld* given_world)
    {
        for (size_t x = 0; x < given_particleAmount; x++)
        {
            inActiveParticles.push_back(new Particle(given_position, given_size, given_shape, given_velocity, given_lifeSpam, given_world));
        };
    }

    void ParticlePool::killParticle(int index)
    {
        activeParticles[index]->Reset();
        //activeParticles[index]->Deactivate();
        inActiveParticles.push_back(activeParticles[index]);
        activeParticles.erase(activeParticles.begin());
    }

    void ParticlePool::ReviveParticle()
    {
        activeParticles.push_back(inActiveParticles[0]);
        inActiveParticles.erase(inActiveParticles.begin());
    }
}