
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024

#include <Box2D/Box2D.h>
#include <memory>
#pragma once
using namespace std;
namespace misi
{
	/// @brief Class that instantiates a b2World with added funtions to create b2Bodies
	class physicWorld
	{
		b2Vec2 gravityForce;
		
		unique_ptr< b2World > worldReference;

	public:

		physicWorld(b2Vec2 given_gravityForce);

		inline unique_ptr< b2World >& getWorldReference()
		{
			return worldReference;
		}

	};
}
