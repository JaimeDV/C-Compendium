/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024
/// @brief Class that implements the classes defined at sphere.hpp

#include "../Headers/Sphere.hpp"
namespace misi
{
	PhysicSphere::PhysicSphere(btVector3 given_rotation, float given_mass,
		btVector3 given_inertia, float given_restitution, ObjectType given_type, btVector3 given_origin)
		: PhysicBody(given_rotation, given_mass, given_inertia, given_restitution, given_type, given_origin)
	{
       
        btCollisionShape* sphereShape = new btSphereShape(1.f);

        btTransform transform;
        transform.setIdentity();
       
        transform.setOrigin(origin);

        btQuaternion quaternion;
        quaternion.setEuler(rotation.x(), rotation.y(), rotation.z());
        transform.setRotation(quaternion);

        btDefaultMotionState* motionState = new btDefaultMotionState(transform);

 
        sphereShape->calculateLocalInertia(given_mass, given_inertia);

 

        btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(given_mass, motionState, sphereShape, given_inertia);
        body = new btRigidBody(rigidBodyCI);

        switch (type) {
            case kinematicObject:
                body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
                body->setActivationState(DISABLE_DEACTIVATION);
                break;
            case staticObject:
                body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_STATIC_OBJECT);
                break;
            default:
                break;
        }

        shared_ptr<Model> model(new Model_Obj("../../assets/sphere.obj"));
        mainModel = model;

        /*shared_ptr< Model       > cube(new Model);
        shared_ptr< Material > cube_material = make_shared< Material >(*Material::default_material());

        cube_material->set("material_color", Vector3(.0f, .5f, .5f));
        shared_ptr< Drawable > cubes_mesh = shared_ptr <Drawable>(new glt::Cube);


        cube->add(cubes_mesh, cube_material);
        mainModel = cube;*/
        volume = Sphere;

	}

}
