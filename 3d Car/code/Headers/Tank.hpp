/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 18/05/2024

#pragma once
#include "Plane.hpp"

namespace misi
{
    /// @brief Class that creates a controllable physicbody that moves
    class Tank : public PhysicPlane
    {
        btVector3 moveSpeed; // Speed vector for the tank's movement

    public:
        /// @brief Constructor for Tank
        /// @param given_rotation The initial rotation of the tank
        /// @param given_mass The mass of the tank
        /// @param given_inertia The inertia of the tank
        /// @param given_restitution The restitution value of the tank
        /// @param given_type The type of the tank
        /// @param given_origin The initial origin of the tank
        /// @param scale The scale of the tank model
        Tank(btVector3 given_rotation, float given_mass, btVector3 given_inertia, float given_restitution, ObjectType given_type,
            btVector3 given_origin, btVector3 scale) : PhysicPlane(given_rotation, given_mass, given_inertia, given_restitution, given_type, given_origin, scale)
        {
            moveSpeed = btVector3(0, 0, 0);
        }

        /// @brief Executes the action of the tank model
        virtual void ModelAction() override;

        /// @brief Sets the movement speed of the tank
        /// @param speed Speed vector for the tank's movement
        void SetMoveSpeed(btVector3 speed)
        {
            moveSpeed = speed;
        }

        /// @brief Destructor only exist to make polymorphic
        virtual ~Tank() {}
    };
}
