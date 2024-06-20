/// @copyright � 2023+ Jaime d�az vi�itez
/// @author Author: Jaime D�az Vi�itez
/// pamecin@gmail.com
/// @date 18/02/2024
/// @brief Class that implements the classes defined at World.hpp 

#include "../Headers/World.hpp"

namespace misi
{
	physicWorld::physicWorld( b2Vec2 given_gravityForce)
	{
		worldReference = std::unique_ptr<b2World>(new b2World(given_gravityForce));
	}

}