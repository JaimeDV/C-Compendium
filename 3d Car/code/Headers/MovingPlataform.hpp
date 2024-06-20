/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 15/05/2024


#pragma once
#include "Plane.hpp"
namespace misi
{
    /// @brief Class that creates a physicbody that moves left and right
    class MovingPlataform : public PhysicPlane
    {

        float moveSpeed; // The speed at which the platform moves
        int waitTime; // The time it takes to change direction in seconds
        int waitTimeAux; // Auxiliary variable to track time

        /// @brief Waits for a certain amount of time before changing direction
        void Wait();

    public:

        /// @brief Constructor for MovingPlataform
        /// @param given_rotation The initial rotation of the platform
        /// @param given_mass The mass of the platform
        /// @param given_inertia The inertia of the platform
        /// @param given_restitution The restitution value of the platform
        /// @param given_type The type of the platform
        /// @param given_origin The initial origin of the platform
        /// @param scale The scale of the platform
        MovingPlataform(btVector3 given_rotation, float given_mass, btVector3 given_inertia, float given_restitution, ObjectType given_type,
            btVector3 given_origin, btVector3 scale) : PhysicPlane(given_rotation, given_mass, given_inertia, given_restitution, given_type, given_origin, scale)
        {
            moveSpeed = 0.5f;
            waitTime = 420;
            waitTimeAux = waitTime;
        }

        /// @brief Performs the action of the platform
        virtual void ModelAction() override;


        /// @brief Destructor only exists to make polymorphic
        virtual ~MovingPlataform() {} 

        /// @brief Set the wait time before changing direction
        /// @param time The time to set
        void SetWaitTime(int time)
        {
            waitTime = time;
            waitTimeAux = waitTime;
        }

        /// @brief Set the move speed of the platform
        /// @param speed The speed to set
        void SetMoveSpeed(float speed)
        {
            moveSpeed = speed;
        }

    };
}