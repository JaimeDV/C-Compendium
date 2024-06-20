/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024

#pragma once
#include "ParticlePool.hpp"
#include "Message.hpp"
namespace misi
{

    /// @brief Updates the status of each particle in the particle pool
    /// For some reason needs some time to wind up
    class ParticleUpdater : public Message_Listener, public std::enable_shared_from_this<ParticleUpdater>
    {
        shared_ptr<ParticlePool> particlePool; // Pointer to the particle pool
        unsigned int particleFlow; // Flow rate of particles
        bool firstStart; // Flag indicating the first update cycle
        bool active; // Flag indicating whether the updater is active
        shared_ptr<Scene> fatherScene = nullptr; // Pointer to the scene
    public:
        /// @brief Constructor for ParticleUpdater
        /// @param given_particlePool Pointer to the particle pool
        /// @param given_particleFlow Flow rate of particles
        ParticleUpdater(shared_ptr<ParticlePool> given_particlePool, unsigned int given_particleFlow) :
            particlePool(given_particlePool), particleFlow(given_particleFlow / 2), active(false), firstStart(true) {}

        /// @brief Sets the listener scene for the particle updater
        /// @param givenScene Pointer to the scene to set as listener
        void SetListener(shared_ptr<Scene> givenScene)
        {
            fatherScene = givenScene;
            auto messenger = make_shared<Message_Dispacher>(givenScene);
            messenger->add(shared_from_this(), "particle");
        }

        /// @brief Updates the position and lifetime based on the t value
        /// @param t Times the function is called per tick
        void Update(float t);

        /// @brief Parses all the messages that match the listener id
        /// @param message Message sent
        virtual void handle(const Message& message) override;
    };

}