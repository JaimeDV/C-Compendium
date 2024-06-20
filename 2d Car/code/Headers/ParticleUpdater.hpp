/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024

#pragma once
#include "ParticlePool.hpp"
#include "Scene.hpp"
namespace misi
{
    /// @brief updates the status of each particle in the particle pool
    ///for some reason needs so time to wind up
    class ParticleUpdater : public Message_Listener
    {
        ParticlePool* particlePool;
        unsigned int particleFlow;
        bool firstStart;
        bool active;
        Scene* fatherScene=nullptr;
        public:
        ParticleUpdater(ParticlePool* given_particlePool, unsigned int given_particleFlow)
        {
            particlePool = given_particlePool;
            particleFlow = given_particleFlow/2;
            active = false;
            firstStart = true;
           
        };
        void SetListener(Scene* givenScene)
        {
            fatherScene=givenScene;
            fatherScene->getMessenger()->add(*this, "particle");
        }
        /// @brief updates the position & lifetime vased on the t value
        /// @param t times the funtion is called per tick
        void Update(float t);
        /// @brief Parses all the messages that matches the listener id
        /// @param Message message send
        virtual void handle(const Message& message) override;
    };

}