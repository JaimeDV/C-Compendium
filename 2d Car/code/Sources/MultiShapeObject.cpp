/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 24/02/2024
/// @brief  Class that instantiates a an object made of multiple b2fixtures

#include "../Headers/MultiShapeObject.hpp"

namespace misi
{
	MultiShapeObject::MultiShapeObject(physicBody* newBody)
	{
		fatherBody = newBody;
	}

	void MultiShapeObject::AddObject(physicBody* newBody, physicWorld& givenWorld)
	{
		bodyList.push_back(newBody);
		auto* joint = CreateJoint(*givenWorld.getWorldReference(), fatherBody->getBody(), newBody->getBody(), 
			true);
		RevoluteJoints.push_back(joint);
	}
	b2RevoluteJoint* MultiShapeObject::CreateJoint(b2World& physics_world, b2Body* body_a, b2Body* body_b, bool enable_motor)
	{
		b2RevoluteJointDef jointDef;

		jointDef.bodyA = body_a;
		jointDef.bodyB = body_b;
		jointDef.enableMotor = enable_motor;
		jointDef.collideConnected = false;
        jointDef.Initialize(body_a, body_b, body_b->GetWorldCenter());
		/*Revolute - a hinge or pin, where the bodies rotate about a common point
			Distance - a point on each body will be kept at a fixed distance apart
			Prismatic - the relative rotation of the two bodies is fixed, and they can slide along an axis
			Line - a combination of revolute and prismatic joints, useful for modelling vehicle suspension
			Weld - holds the bodies at the same orientation
			Pulley - a point on each body will be kept within a certain distance from a point in the world,
		where the sum of these two distances is fixed, kinda... (sheesh... there is no succinct way to describe this)
			Friction - reduces the relative motion between the two bodies
			Gear - controls two other joints(revolute or prismatic) so that the movement of one affects the other
			Mouse - pulls a point on one body to a location in the world*/

		return dynamic_cast<b2RevoluteJoint*>(physics_world.CreateJoint(&jointDef));
	}


	void MultiShapeObject::AddPolygonFixture(b2Vec2 position, b2Vec2 given_vertices, float density, float restitution,
		float friction, bool iscube)
	{
		if (!iscube)
		{
			b2PolygonShape body_shape;
			body_shape.Set(&given_vertices, int32(given_vertices.Length()));
			body_shape.m_centroid = position;

			b2FixtureDef body_fixture;
			body_fixture.shape = &body_shape;
			body_fixture.density = density;
			body_fixture.restitution = restitution;
			body_fixture.friction = friction;

			fatherBody->getBody()->CreateFixture(&body_fixture);

		}
		else
		{
			b2PolygonShape body_shape;

			body_shape.SetAsBox(given_vertices.x, given_vertices.y, position, 0);

			b2FixtureDef body_fixture;

			body_fixture.shape = &body_shape;
			body_fixture.density = density;
			body_fixture.restitution = restitution;
			body_fixture.friction = friction;

			fatherBody->getBody()->CreateFixture(&body_fixture);

		}

	}

	void MultiShapeObject::AddSphereFixture(b2Vec2 position, float radius,float density, float restitution,
		float friction)
	{
		b2CircleShape body_shape;

		body_shape.m_radius = radius;
		body_shape.m_p.Set(position.x+ fatherBody->getBody()->GetPosition().x, position.y+ fatherBody->getBody()->GetPosition().y);
		b2FixtureDef body_fixture;

		body_fixture.shape = &body_shape;
		body_fixture.density = density;
		body_fixture.restitution = restitution;
		body_fixture.friction = friction;

		fatherBody->getBody()->CreateFixture(&body_fixture);

	}
	void MultiShapeObject::AddEdgeFixture(b2Vec2 positionA, b2Vec2 positionB, float density, float restitution,
		float friction)
	{
		b2EdgeShape body_shape;

		body_shape.SetTwoSided(positionA, positionB);
		b2FixtureDef body_fixture;

		body_fixture.shape = &body_shape;
		body_fixture.density = density;
		body_fixture.restitution = restitution;
		body_fixture.friction = friction;

		fatherBody->getBody()->CreateFixture(&body_fixture);
	}
    void MultiShapeObject::AddMotorJoint(b2Body* bodyToAdd)
    {
        b2RevoluteJointDef joint;
        joint.enableMotor=true;
        joint.Initialize(fatherBody->getBody(), bodyToAdd,bodyToAdd->GetWorldCenter());
        b2RevoluteJoint* revJoint= (b2RevoluteJoint*)fatherBody->getWorld()->getWorldReference()->CreateJoint(&joint);
        RevoluteJoints.push_back(revJoint);

        //PAra el push usar el pulley joint siendo el de abajo un static

    }

	void MultiShapeObject::AddpPulleyJoint(b2Body* bodyToAdd)
	{
		b2PulleyJointDef joint;
		joint.Initialize(fatherBody->getBody(), bodyToAdd, bodyToAdd->GetWorldCenter(),
			fatherBody->getBody()->GetWorldCenter(), bodyToAdd->GetWorldCenter(),
			fatherBody->getBody()->GetWorldCenter(),1);
		b2PulleyJoint* revJoint = (b2PulleyJoint*)fatherBody->getWorld()->getWorldReference()->CreateJoint(&joint);
		
	}

    void MultiShapeObject::AddRevoluteJoint(b2Body* bodyToAdd)
    {
        b2RevoluteJointDef joint;
        joint.Initialize(fatherBody->getBody(), bodyToAdd, bodyToAdd->GetWorldCenter());
        b2RevoluteJoint* revJoint = (b2RevoluteJoint*)fatherBody->getWorld()->getWorldReference()->CreateJoint(&joint);
        RevoluteJoints.push_back(revJoint);
    }

    void MultiShapeObject::AddWeldJoint(b2Body* bodyToAdd)
    {
        b2WeldJointDef joint;
        joint.Initialize(fatherBody->getBody(), bodyToAdd, bodyToAdd->GetWorldCenter());
        b2WeldJointDef* revJoint = (b2WeldJointDef*)fatherBody->getWorld()->getWorldReference()->CreateJoint(&joint);
    }
    void MultiShapeObject::AddSpeed(float given_speed)
    {
        for each (b2RevoluteJoint * joint in RevoluteJoints)
        {
            joint->SetMotorSpeed(given_speed);
        }

    }

    void MultiShapeObject::SetTorque(float given_torque)
    {
        for each (b2RevoluteJoint * joint in RevoluteJoints)
        {
            joint->SetMaxMotorTorque(given_torque);
        }

    }
}