
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024


#include <Box2D/Box2D.h>
#include "World.hpp"
#include <memory>
#pragma once

namespace misi
{
	/// @brief Father abstract class for all physicalObjects, contains definitions shared between all the types of shape
	class physicBody
	{

		protected:

			b2Vec2 position;

			enum b2BodyType bodyType;

			b2Body* body=nullptr;

			float angle;

			float density;

			float restitution;

			float friction;

            physicWorld* world;

			public:

			physicBody(b2Vec2 given_position,
				enum b2BodyType given_bodyType, float given_angle, float given_density, float given_restitution,
				float given_friction, physicWorld* given_world, bool isSensor, uint16_t layer, uint16_t collides);


			/// @brief B2Body getter
			inline b2Body* getBody()
			{
				return body;
			}

			/// @brief physicWorld getter
            inline physicWorld* getWorld()
            {
                return world;
            }

			

	};
}
