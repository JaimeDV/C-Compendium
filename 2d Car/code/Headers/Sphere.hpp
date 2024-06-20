/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024


#pragma once
#include "Body.hpp"
namespace misi
{
	/// @brief  Class that instantiates a b2CircleShape with the given values
	class PhysicSphere : public physicBody
	{

		float  radius;

	public:

		PhysicSphere(b2Vec2 given_position,
			b2BodyType given_bodyType, float given_angle, float given_density,
			float given_restitution, float given_friction, physicWorld* given_world, 
			float given_radius, bool isSensor,uint16_t layer, uint16_t collides);
	};
}
