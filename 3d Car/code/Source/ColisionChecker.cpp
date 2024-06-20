

/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 15/05/2024
/// @brief Class that implements the classes defined at ColissionChecker.hpp

#include "../Headers/ColisionChecker.hpp"
namespace misi
{

	void ColisionChecker::CheckColisions()
	{
		int manifold_count = world.getDispatcher()->getNumManifolds();
		for (int i = 0; i < manifold_count; i++)
		{
			btPersistentManifold* manifold =
				world.getDispatcher()->getManifoldByIndexInternal(i);
			btCollisionObject* object_a = (btCollisionObject*)(manifold->getBody0());
			btCollisionObject* object_b = (btCollisionObject*)(manifold->getBody1());
			int numContacts = manifold->getNumContacts();
			for (int j = 0; j < numContacts; j++)
			{
				btManifoldPoint& point = manifold->getContactPoint(j);
				if (point.getDistance() < 0.f)
				{

					for (const auto& model : listeners)
					{
						model->HandleColision(object_a, object_b);
					}
					
				}
			}
		}
	}
	
}