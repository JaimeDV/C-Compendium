/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 14/05/2024


#pragma once
#include "Body.hpp"
#include "Cube.hpp"
namespace misi
{
    /// @brief Class that instantiates a btBoxShape with the given values
    class PhysicPlane : public PhysicBody
    {

    public:
        /// @brief Constructor for PhysicPlane
        /// @param given_rotation Initial rotation of the plane
        /// @param given_mass Mass of the plane
        /// @param given_inertia Inertia of the plane
        /// @param given_restitution Restitution coefficient of the plane
        /// @param given_type Type of the plane (static, dynamic, kinematic)
        /// @param given_origin Origin position of the plane
        /// @param scale Scale of the plane
        PhysicPlane(btVector3 given_rotation, float given_mass,
            btVector3 given_inertia, float given_restitution, ObjectType given_type,
            btVector3 given_origin, btVector3 scale);

        /// @brief Destructor only exist to make polymorphic
        virtual ~PhysicPlane() {} 
    };
}
