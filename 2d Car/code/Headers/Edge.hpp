/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024
#pragma once

#include "Body.hpp"
namespace misi
{
	/// @brief  Class that instantiates a b2EdgeShape with the given parameters
	class PhysicEdge :public physicBody
	{

	public:

		PhysicEdge(b2Vec2 given_position,
			b2BodyType given_bodyType, float given_angle, float given_density,
			float given_restitution, float given_friction, physicWorld* given_world,
			b2Vec2 position_a, b2Vec2 position_b, bool isSensor, uint16_t layer, uint16_t collides);

	};
}

