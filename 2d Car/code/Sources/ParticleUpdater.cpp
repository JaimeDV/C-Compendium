/// @copyright © 2023 + Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024
/// @brief implements classes defined in particle updater.hpp

#include "../Headers/ParticleUpdater.hpp"
#include "../Headers/Scene.hpp"
namespace misi
{
    void ParticleUpdater::Update(float t)
    {
        if(firstStart || active)
        {
            vector<Particle*> ParticleIterator = particlePool->GetActive();
            if (ParticleIterator.size() > 0)
            {
                for (int x = int(ParticleIterator.size() - 1); x >= 0; x--)
                {
              
                    ParticleIterator[x]->moveparticle(ParticleIterator[x]->velocity);
                    //ParticleIterator[x]->position += ParticleIterator[x]->velocity;
                    ParticleIterator[x]->lifeSpam -= t;
                    if (ParticleIterator[x]->lifeSpam <= 0)
                    {
                        particlePool->killParticle(x);
                        firstStart = false;
                    }

                }

            }
            while (particlePool->GetActive().size() < particleFlow)
            {
                particlePool->ReviveParticle();
            }

        }

    }
    void ParticleUpdater::handle(const Message& message)
    {
        std::string key;
        parameter value;
        for (const auto& entry : message.parameters) {
            key = entry.first;
            value = entry.second;
        }
        if (key == "start Emision")
        {
            active = true;
        }
    }
}