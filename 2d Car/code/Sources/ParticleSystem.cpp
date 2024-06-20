/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 09/03/2024
/// @brief implements classes defined at ParticleSystem.hpp

#include "../Headers/ParticleSystem.hpp"
namespace misi
{
	ParticleSystem::ParticleSystem(Vector2f particle_position, Vector2f particle_size,
		shapeType given_shape,Vector2f particle_velocity, float particle_lifeSpam,unsigned int particleFlow,
		RenderWindow* window, physicWorld* given_world)
	{
		pool = new ParticlePool(particleFlow, particle_position, particle_size,
			given_shape, particle_velocity, particle_lifeSpam, given_world);
		renderer = new ParticleRenderer(pool, window);
		updater = new ParticleUpdater(pool, particleFlow);
	}
}