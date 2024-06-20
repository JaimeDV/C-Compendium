/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024
/// @brief Class that implements the classes defined at World.hpp 

#include "../Headers/World.hpp"

namespace misi
{
	physicWorld::physicWorld(btVector3 given_gravity) : collisionDispatcher(&collisionConfiguration)
	{
		// Initialize collisionDispatcher in the constructor
		worldReference = make_shared<btDiscreteDynamicsWorld>
			(
				&collisionDispatcher,
				&overlappingPairCache,
				&constraintSolver,
				&collisionConfiguration
			);
		worldReference->setGravity(given_gravity);
	}

}