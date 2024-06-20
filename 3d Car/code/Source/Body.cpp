/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024
/// @brief Class that implements the constructor defined at body.hpp

#include "../Headers/Body.hpp"

namespace misi
{
	PhysicBody::PhysicBody(btVector3 given_rotation, float given_mass, btVector3 given_inertia,
		float given_restitution, ObjectType given_type, btVector3 given_origin)
		:rotation(given_rotation), mass(given_mass), localInertia(given_inertia), type(given_type),
		restitution(given_restitution), origin(given_origin)
	{

	}

	void PhysicBody::AddhidgeConection(shared_ptr< PhysicBody> target , btVector3 hidge_origin, btVector3 localAorigin, btVector3 localBorigin)
	{
		btTransform localA, localB;
		localA.setIdentity();
		localB.setIdentity();

		localA.setOrigin(localAorigin); 
		localB.setOrigin(localBorigin);

		auto hinge = make_shared<btHingeConstraint>(*body, *target->Getbody(), localA, localB);

		localA.getBasis().setEulerZYX(0, 0, 0); 
		localB.getBasis().setEulerZYX(0, 0, 0); 

		hindgeConection.push_back(hinge);



	}
}