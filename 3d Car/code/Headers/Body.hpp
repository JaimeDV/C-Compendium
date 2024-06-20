
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 12/05/2024


#pragma once
#include "World.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace glt;
namespace misi
{
    // Enum that indicates the physic interaction of the physicbody
    enum ObjectType
    {
        staticObject = 0,
        dynamicObject,
        kinematicObject
    };

    // Enum that indicates what the 3d rigidbody shape
    enum Volume
    {
        Cube = 0,
        Sphere,
        none,
    };

    /// @brief Father abstract class for all physicalObjects, contains definitions shared between all the types of shape
    class PhysicBody
    {
    protected:

        // Quaternion representation of the object rotation
        btQuaternion quaternion;

        // Euler representation the object rotation
        btVector3 rotation;

        // Scalar representation of the object mass, used for physic calculations
        btScalar  mass;

        // Inertia value
        btVector3 localInertia;

        // Amount of power loss when moving
        btScalar restitution;

        // Pointer to the Node that draws in the viewport the assigned rigidbody model
        shared_ptr <Model> mainModel;

        // Unique string identifier used in the render node 
        std::string modelName = "  ";

        // Enum that indicates the physic interaction of the physicbody
        ObjectType type;

        // Pointer to the physic rigid body object
        btRigidBody* body = nullptr;

        // Reference to the model transform matrix
        btTransform transform;

        // Model position on the 3d scene
        btVector3 origin;

        // Enum that indicates what the 3d rigidbody shape
        Volume volume = none;

        // Scale factor 
        btVector3 scale;

        // List of all hinge connections the object has
        vector<shared_ptr< btHingeConstraint>> hindgeConection;

    public:


        /// @brief Constructor for PhysicBody
        /// @param given_rotation The initial rotation of the object
        /// @param given_mass The mass of the object
        /// @param given_inertia The inertia of the object
        /// @param restitution The restitution value
        /// @param given_type The type of the object
        /// @param given_origin The initial origin of the object
        PhysicBody(btVector3 given_rotation, float given_mass,
            btVector3 given_inertia, float restitution, ObjectType given_type, btVector3 given_origin);

        /// @brief Given a vector3 changes the model origin
        /// @param origin Vector representation of the new object position
        void setOrigin(btVector3 origin)
        {
            transform.setIdentity();
            transform.setOrigin(origin);
        }

        /// @brief Given a vector3 changes the model origin
        /// @param origin Vector representation of the new object position
        void SetName(std::string given_name)
        {
            modelName = given_name;
        }

        /// @brief Get the name of the model
        /// @return The model name
        string GetName()
        {
            return modelName;
        }

        /// @brief Get the model
        /// @return The model
        shared_ptr <Model> GetModel()
        {
            return mainModel;
        }

        /// @brief Get the body
        /// @return The body
        btRigidBody* Getbody()
        {
            return body;
        }

        /// @brief Get the volume
        /// @return The volume
        Volume Getvolume()
        {
            return volume;
        }

        /// @brief Get the type
        /// @return The type
        ObjectType GetType()
        {
            return type;
        }

        /// @brief Get the scale
        /// @return The scale
        btVector3 GetScale()
        {
            return scale;
        }

        /// @brief Get the hinge connections
        /// @return The hinge connections
        vector<shared_ptr< btHingeConstraint>> GetHidges()
        {
            return hindgeConection;
        }

        /// @brief Set the velocity
        /// @param velocity The velocity to set
        void SetVelocity(btVector3 velocity)
        {
            body->setLinearVelocity(velocity);
        }

        /// @brief Set the volume
        /// @param given_volume The volume to set
        void SetVolume(Volume given_volume)
        {
            volume = given_volume;
        }

        /// @brief Lock the rotation
        void LockRotation()
        {
            body->setAngularFactor(btVector3(0, 0, 0));
        }

        /// @brief Unlock the rotation
        void UnLockRotation()
        {
            body->setAngularFactor(btVector3(1, 1, 1));
        }

        /// @brief Disable gravity
        void DisableGravity()
        {
            body->setGravity(btVector3(0, 0, 0));
        }

        /// @brief Disable the model
        void DisableModel()
        {
            body->setActivationState(DISABLE_SIMULATION);
            body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
        }

        /// @brief Add a hinge connection
        /// @param target The target physic body
        /// @param hidge_origin The hinge origin
        /// @param localAorigin The local origin A
        /// @param localBorigin The local origin B
        void AddhidgeConection(shared_ptr< PhysicBody> target, btVector3 hidge_origin, btVector3 localAorigin, btVector3 localBorigin);

        /// @brief Apply motor force
        /// @param velocity The velocity
        /// @param force The force
        void ApplyMotorForce(float velocity, float force)
        {
            for (const auto& hindge : hindgeConection)
            {
                hindge->enableAngularMotor(true, velocity, force); // Enable motor with target velocity of 1.0 rad/sec and max impulse of 10.0
            }
        }

        /// @brief Handle collision
        /// @param object_a The first collision object
        /// @param object_b The second collision object
        virtual void HandleColision(btCollisionObject* object_a, btCollisionObject* object_b) { };

        /// @brief Model action
        virtual void ModelAction() { };

        /// @brief Destructor only exist to make polymorfic
        virtual ~PhysicBody() {}
    };
}