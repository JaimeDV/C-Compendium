/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/02/2024
/// @brief Class that implements the classes defined at Plane.hpp

#include "../Headers/Plane.hpp"
namespace misi
{
    PhysicPlane::PhysicPlane(btVector3 given_rotation, float given_mass,
        btVector3 given_inertia, float given_restitution, ObjectType given_type, btVector3 given_origin, btVector3 given_scale)
        : PhysicBody(given_rotation, given_mass, given_inertia, given_restitution, given_type, given_origin)
    {

        scale = given_scale;
        btCollisionShape* planeShape = new btBoxShape(scale);

        btTransform transform;
        transform.setIdentity();

        transform.setOrigin(origin);

        btQuaternion quaternion;
        quaternion.setEuler(rotation.x(), rotation.y(), rotation.z());
        transform.setRotation(quaternion);

        btDefaultMotionState* motionState = new btDefaultMotionState(transform);


        planeShape->calculateLocalInertia(given_mass, given_inertia);



        btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(given_mass, motionState, planeShape, given_inertia);
        body = new btRigidBody(rigidBodyCI);

        switch (type) {
        case kinematicObject:
            body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
            body->setActivationState(DISABLE_DEACTIVATION);
            
            break;
        case staticObject:
            body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_STATIC_OBJECT);
            break;
        case dynamicObject:
            body->setActivationState(DISABLE_DEACTIVATION);
        default:
            break;
        }

        shared_ptr< Model > cube(new Model);
        shared_ptr< Material > cube_material = make_shared< Material >(*Material::default_material());

        cube_material->set("material_color", Vector3(.0f, .5f, .5f));
        shared_ptr< Drawable > cubes_mesh = shared_ptr <Drawable>(new glt::Cube);


        cube->add(cubes_mesh, cube_material);
        mainModel = cube;
        volume = Cube;
        

    }

}
