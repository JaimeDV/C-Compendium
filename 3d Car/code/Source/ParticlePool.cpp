/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024
/// @brief implements particle pool hpp clases 

#include "../Headers/ParticlePool.hpp"
namespace misi
{
    void ParticlePool::InstantiatePool(btVector3 given_rotation, float given_mass,
        btVector3 given_inertia, float restitution, ObjectType given_type, btVector3 given_origin,
        btVector3 given_size, btVector3 given_velocity, float given_lifeSpam, shared_ptr<Scene> given_world, int particleAmount)
    {
        for (size_t x = 0; x < particleAmount; x++)
        {
		    auto particle =make_shared <Particle>( given_rotation,  given_mass,  given_inertia,  restitution,  given_type,  given_origin,
            given_size,  given_velocity,  given_lifeSpam, given_world, x);
            inActiveParticles.push_back(particle);
        };
    }

    void ParticlePool::killParticle(int index)
    {
        activeParticles[index]->Reset();
        //activeParticles[index]->Deactivate();
        /*inActiveParticles.push_back(activeParticles[index]);
        activeParticles.erase(activeParticles.begin());*/
    }

    void ParticlePool::ReviveParticle()
    {
        activeParticles.push_back(inActiveParticles[0]);
        inActiveParticles.erase(inActiveParticles.begin());
    }
}