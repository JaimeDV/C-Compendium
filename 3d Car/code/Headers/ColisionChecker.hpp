
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 15/05/2024


#pragma once
#include "Plane.hpp"
namespace misi
{
    /// @brief Auxiliary class that manages collisions between rigidbodies
    class ColisionChecker
    {
        btDiscreteDynamicsWorld& world; // Reference to the physics world to check for collisions
        vector<shared_ptr< PhysicBody >> listeners; // List of listeners to be notified of collisions

    public:

        /// @brief Constructor for ColisionChecker
        /// @param given_world The physics world to check for collisions
        ColisionChecker(btDiscreteDynamicsWorld& given_world) : world(given_world)
        {

        }

        /// @brief Checks for collisions and notifies listeners
        void CheckColisions();

        /// @brief Adds a listener to be notified of collisions
        /// @param listener The PhysicBody to add as a listener
        void AddListener(shared_ptr< PhysicBody > listener)
        {
            listeners.push_back(listener);
        }

    };
}