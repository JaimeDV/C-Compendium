/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024
/// @brief Class that implements the constructor defined at body.hpp

#include "../Headers/Body.hpp"

namespace misi
{
	physicBody::physicBody(b2Vec2 given_position,
		enum b2BodyType given_bodyType, float given_angle, float given_density, float given_restitution,
		float given_friction, physicWorld* given_world, bool isSensor, uint16_t layer, uint16_t collides)
	{
		position = given_position;
		bodyType = given_bodyType;
		angle = given_angle;
		density = given_density;
		restitution = given_restitution;
		friction = given_restitution;
        world = given_world;
	}
}