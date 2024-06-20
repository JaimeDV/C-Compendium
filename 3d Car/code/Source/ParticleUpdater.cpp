/// @copyright © 2023 + Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024
/// @brief implements classes defined in particle updater.hpp

#include "../Headers/ParticleUpdater.hpp"

namespace misi
{
    void ParticleUpdater::Update(float t)
    {
        if(firstStart || active)
        {
            vector<shared_ptr<Particle> > ParticleIterator = particlePool->GetActive();
            if (ParticleIterator.size() > 0)
            {
                for (int x = int(ParticleIterator.size() - 1); x >= 0; x--)
                {
              
                    ParticleIterator[x]->MoveParticle(ParticleIterator[x]->Getvelocity());
                    //ParticleIterator[x]->position += ParticleIterator[x]->velocity;
                    ParticleIterator[x]->SetLifeSpam(ParticleIterator[x]->GetLifeSpam()-t);
                    if (ParticleIterator[x]->GetLifeSpam() <= 0)
                    {
                        particlePool->killParticle(x);
                        /*firstStart = false;*/
                    }

                }

            }
            while (particlePool->GetActive().size() < particleFlow)
            {
                particlePool->ReviveParticle();
            }
            //temporal workaround
            ParticleIterator = particlePool->GetInActive();
            if (ParticleIterator.size() > 0)
            {
                for (int x = int(ParticleIterator.size() - 1); x >= 0; x--)
                {

                    ParticleIterator[x]->MoveParticle(ParticleIterator[x]->Getvelocity());
                    //ParticleIterator[x]->position += ParticleIterator[x]->velocity;
                    ParticleIterator[x]->SetLifeSpam(ParticleIterator[x]->GetLifeSpam() - t);
                    if (ParticleIterator[x]->GetLifeSpam() <= 0)
                    {
                        particlePool->killParticle(x);
                        firstStart = false;
                    }

                }

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