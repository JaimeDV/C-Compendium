/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024
#pragma once


#include "Sphere.hpp"
namespace misi
{
    class Scene;

    /// @brief Encapsulates the particles emitted by the particle system
    class Particle
    {
        btVector3 particleSize; // Size of the particle
        btVector3 Maxvelocity; // Maximum velocity of the particle
        btVector3 velocity; // Current velocity of the particle
        float lifeSpam; // Lifespan of the particle
        float maxSpam; // Maximum lifespan of the particle
        int id = 0; // Identifier of the particle

    public:
        shared_ptr<PhysicSphere> body; // Pointer to the physics body of the particle
        shared_ptr<Scene> worldReference; // Pointer to the scene where the particle exists

        /// @brief Constructor for Particle
        /// @param given_rotation The initial rotation of the particle
        /// @param given_mass The mass of the particle
        /// @param given_inertia The inertia of the particle
        /// @param restitution The restitution value of the particle
        /// @param given_type The type of the particle
        /// @param given_origin The initial origin of the particle
        /// @param given_size The size of the particle
        /// @param given_velocity The initial velocity of the particle
        /// @param given_lifeSpam The lifespan of the particle
        /// @param given_world The scene where the particle exists
        /// @param gId The ID of the particle
        Particle(btVector3 given_rotation, float given_mass,
            btVector3 given_inertia, float restitution, ObjectType given_type, btVector3 given_origin,
            btVector3 given_size, btVector3 given_velocity, float given_lifeSpam, shared_ptr<Scene> given_world, int gId);

        /// @brief Moves the particle position following the given speed vector
        /// @param velocity The amount of movement made in one game tick
        void MoveParticle(btVector3 velocity);

        /// @brief Resets all the particle values and adds a little randomness to the position
        void Reset();

        /// @brief Deactivates the particle unimplemented due to render bugs
        void Deactivate();

        /// @brief Reactivates the particle
        void Reactivate();

        /// @brief Sets the ID of the particle
        /// @param gId The ID to set
        void SetId(int gId)
        {
            id = gId;
        }

        /// @brief Gets the ID of the particle
        /// @return The ID of the particle as a string
        string GetId()
        {
            return std::to_string(id);
        }

        /// @brief Sets the lifespan of the particle
        /// @param new_value The new lifespan value
        void SetLifeSpam(float new_value)
        {
            lifeSpam = new_value;
        }

        /// @brief Gets the lifespan of the particle
        /// @return The lifespan of the particle
        float GetLifeSpam()
        {
            return lifeSpam;
        }

        /// @brief Gets the velocity of the particle
        /// @return The velocity of the particle
        btVector3 Getvelocity()
        {
            return velocity;
        }

        /// @brief Gets the physics body of the particle
        /// @return Pointer to the physics body of the particle
        shared_ptr<PhysicSphere> GetBody()
        {
            return body;
        }

        /// @brief Gets the scene where the particle exists
        /// @return Pointer to the scene where the particle exists
        shared_ptr<Scene> GetWorld()
        {
            return worldReference;
        }

        /// @brief Destructor only exists to make polymorphic
        virtual ~Particle() {}
    };
}