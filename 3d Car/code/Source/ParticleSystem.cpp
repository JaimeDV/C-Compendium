/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 09/03/2024
/// @brief implements classes defined at ParticleSystem.hpp

#include "../Headers/ParticleSystem.hpp"
namespace misi
{
	ParticleSystem::ParticleSystem(btVector3 given_rotation, float given_mass,
		btVector3 given_inertia, float restitution, ObjectType given_type, btVector3 given_origin,
		btVector3 given_size, btVector3 given_velocity, float given_lifeSpam, shared_ptr<Scene> given_world, int particleAmount,
		unsigned int particleFlow)
	{
		pool =make_shared<ParticlePool>( given_rotation,  given_mass,
			 given_inertia,  restitution,  given_type,  given_origin,
			 given_size,  given_velocity,  given_lifeSpam, given_world, particleAmount);
		
		updater=  make_shared <ParticleUpdater>(pool, particleFlow);
	}
}