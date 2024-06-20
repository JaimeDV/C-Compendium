/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 12/05/2024

#pragma once
#include "Body.hpp"

namespace misi
{
    /// @brief Class that instantiates a btSphereShape with the given values
    class PhysicSphere : public PhysicBody
    {
        float radius = 1.0f;  // Radius of the sphere

    public:
        /// @brief Constructor for PhysicSphere
        /// @param given_rotation The initial rotation of the sphere
        /// @param given_mass The mass of the sphere
        /// @param given_inertia The inertia of the sphere
        /// @param given_restitution The restitution value of the sphere
        /// @param given_type The type of the sphere
        /// @param given_origin The initial origin of the sphere
        PhysicSphere(btVector3 given_rotation, float given_mass,
            btVector3 given_inertia, float given_restitution, ObjectType given_type, btVector3 given_origin);

        /// @brief Destructor only exist to make polymorphic
        virtual ~PhysicSphere() {}
    };
}
