/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024
/// @brief Class that implements the classes defined at Polygon.hpp

#include "../Headers/Polygon.hpp"
namespace misi
{
    PhysicPolygon::PhysicPolygon(b2Vec2 given_position,
        b2BodyType given_bodyType, float given_angle, float given_density,
        float given_restitution, float given_friction, physicWorld* given_world,
        bool given_isCube, b2Vec2 given_vertices, bool isSensor, uint16_t layer, uint16_t collides) :
        physicBody(given_position, given_bodyType, given_angle,
            given_density, given_restitution, given_friction, given_world, isSensor, layer, collides)
    {
        b2BodyDef bodyDefinition;

        bodyDefinition.type = bodyType;
        bodyDefinition.position.Set(position.x, position.y);
        bodyDefinition.angle = given_angle;

        b2Body* newBody = given_world->getWorldReference()->CreateBody(&bodyDefinition);
        body = newBody;

        if (given_isCube)
        {

            b2PolygonShape body_shape;

            body_shape.SetAsBox(given_vertices.x, given_vertices.y, position,0);

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
        else
        {
            b2PolygonShape body_shape;

            body_shape.Set(&given_vertices, int32(given_vertices.Length()));

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

}
