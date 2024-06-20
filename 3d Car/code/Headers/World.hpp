
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// @date 12/05/2024
/// @date 18/02/2024
///All code is unsued, for some reason it doesn't work if world is inside here,all the code has been moved to scene
#pragma once
#include <memory>
#include "btBulletDynamicsCommon.h"
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <OpenGL.hpp>
#include <Render_Node.hpp>
using namespace std;
namespace misi
{
	//@brief unsued class, is only here for the header references 
	class physicWorld
	{

		btVector3 gravityForce;

		shared_ptr<btDiscreteDynamicsWorld> worldReference;

		btDefaultCollisionConfiguration collisionConfiguration;

		btCollisionDispatcher collisionDispatcher;

		btDbvtBroadphase overlappingPairCache;

		btSequentialImpulseConstraintSolver constraintSolver;

	public:

		physicWorld(btVector3 given_gravity);

		shared_ptr<btDiscreteDynamicsWorld>  GetWorldReference()
		{
			return worldReference;
		}

		void AddModel(shared_ptr< btRigidBody > model)
		{
			worldReference->addRigidBody(model.get());
		}


	};
}
