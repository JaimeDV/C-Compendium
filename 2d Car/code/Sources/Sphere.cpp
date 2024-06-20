/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024
/// @brief Class that implements the classes defined at sphere.hpp

#include "../Headers/Sphere.hpp"
#include "../Headers/Collision.hpp"
namespace misi
{
	PhysicSphere::PhysicSphere(b2Vec2 given_position,
		b2BodyType given_bodyType, float given_angle, float given_density,
		float given_restitution, float given_friction, physicWorld* given_world, float given_radius, bool isSensor, 
        uint16_t layer, uint16_t collides) :
		physicBody(given_position, given_bodyType, given_angle,
			given_density, given_restitution, given_friction, given_world, isSensor, layer, collides)
	{
        radius = given_radius;

        b2BodyDef bodyDefinition;
        bodyDefinition.type = bodyType;
        bodyDefinition.position.Set(position.x, position.y);    
        bodyDefinition.angle = given_angle;


        b2Body* newBody = given_world->getWorldReference()->CreateBody(&bodyDefinition);
        body = newBody;
       
        b2CircleShape body_shape;

        body_shape.m_radius = radius;

        b2FixtureDef body_fixture;

        body_fixture.shape = &body_shape;
        body_fixture.density = density;
        body_fixture.restitution = restitution;
        body_fixture.friction = friction;
        body_fixture.isSensor = isSensor;
        body_fixture.filter.categoryBits = layer; 
        body_fixture.filter.maskBits = collides;
        body->CreateFixture(&body_fixture);
	}
   

}
