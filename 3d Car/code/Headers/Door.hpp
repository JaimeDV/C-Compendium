/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 15/05/2024


#pragma once
#include "Plane.hpp"
#include "Message.hpp"
namespace misi
{
    /// @brief Class that creates a physicbody acting as a door, when triggered the joint moves allowing movement
    class DoorModel : public PhysicPlane
    {

        bool trigered = false; // Flag indicating if the door is triggered

    public:

        /// @brief Constructor for DoorModel
        /// @param given_rotation The initial rotation of the door
        /// @param given_mass The mass of the door
        /// @param given_inertia The inertia of the door
        /// @param given_restitution The restitution value of the door
        /// @param given_type The type of the door
        /// @param given_origin The initial origin of the door
        /// @param scale The scale of the door
        DoorModel(btVector3 given_rotation, float given_mass, btVector3 given_inertia, float given_restitution, ObjectType given_type,
            btVector3 given_origin, btVector3 scale) : PhysicPlane(given_rotation, given_mass, given_inertia, given_restitution, given_type, given_origin, scale)
        {

        }

        /// @brief Opens the door when the trigger mesage is recived
        virtual void ModelAction() override
        {
            if (trigered)
            {
                UnLockRotation();
                ApplyMotorForce(0.2f, 1.f);
            }
        }

        /// @brief Trigger the door
        void Trigger();

        /// @brief Destructor only exist to make polymorphic
        virtual ~DoorModel() {} 

    };

    /// @brief Class representing a door
    class Door :public Message_Listener
    {

        shared_ptr <DoorModel> doormodel; // Pointer to the door model

    public:

        /// @brief Handle message
        virtual void handle(const Message& message) override;

        /// @brief Constructor for Door
        /// @param given_rotation The initial rotation of the door
        /// @param given_mass The mass of the door
        /// @param given_inertia The inertia of the door
        /// @param given_restitution The restitution value of the door
        /// @param given_type The type of the door
        /// @param given_origin The initial origin of the door
        /// @param scale The scale of the door
        Door(btVector3 given_rotation, float given_mass, btVector3 given_inertia, float given_restitution, ObjectType given_type,
            btVector3 given_origin, btVector3 scale)
        {
            doormodel = make_shared <DoorModel>(given_rotation, given_mass, given_inertia, given_restitution, given_type, given_origin, scale);
        }

        /// @brief Get the door model
        /// @return The door model
        shared_ptr <DoorModel> GetModel()
        {
            return doormodel;
        }
    };
}