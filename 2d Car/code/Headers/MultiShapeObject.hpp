/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 24/02/2024

#include "Sphere.hpp"
#include "Edge.hpp"
#include "Polygon.hpp"
#include "vector"

#pragma once
namespace misi
{
	enum fixtureType
	{
		cube=0,
		polygon,
		sphere,
		edge
	};
	/// @brief  Class that instantiates an object made of multiple b2fixtures
	class MultiShapeObject
	{
		vector<physicBody*> bodyList;
		vector<b2RevoluteJoint*> RevoluteJoints;
		physicBody* fatherBody=nullptr;
		

		///Unused
		b2RevoluteJoint* CreateJoint(b2World& physics_world, b2Body* body_a, b2Body* body_b, bool enable_motor = false);

		public:

		MultiShapeObject(physicBody* firstBody);

		//Unusued
		void AddObject(physicBody* newBody, physicWorld& given_world);

		/// @brief adds a poligonfixture at the given position
		void AddPolygonFixture(b2Vec2 position, b2Vec2 given_vertices,float density, float restitution,
			float friction, bool iscube);

		/// @brief adds a sphere at the given position
		void AddSphereFixture(b2Vec2 position, float radious, float density, float restitution,
			float friction);

		/// @brief adds a fixture at the given position
		void AddEdgeFixture(b2Vec2 positionA, b2Vec2 positionB, float density, float restitution,
			float friction);
        
		/// @brief conect the father body with a new b2body using a revolute joint with motor enabled
		/// @param bodyToAdd b2bdoy to conect
        void AddMotorJoint(b2Body* bodyToAdd);


		/// @brief conect the father body with a new b2body using a revolute joint with motor disabled
		/// @param bodyToAdd b2bdoy to conect
        void AddRevoluteJoint(b2Body* bodyToAdd);


		/// @brief conect the father body with a new b2body using a weld joint
		/// @param bodyToAdd b2bdoy to conect
        void AddWeldJoint(b2Body* bodyToAdd);


		/// @brief conect the father body with a new b2body using a pulley joint with motor enabled
		/// @param bodyToAdd b2bdoy to conect
		void AddpPulleyJoint(b2Body* bodyToAdd);

		/// @brief Sets the motor speed of all the motor joints the object has conected to
		/// @param speed amount of speed to add,negative values equal right movements,  left positive
        void AddSpeed(float speed);

		/// @brief Sets the tourge of all the motor joints the object has conected to
		/// @param speed amount of speed to add,negative values equal right movements,  left positive
        void SetTorque(float tourge);
	};
}