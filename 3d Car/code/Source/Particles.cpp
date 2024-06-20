/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024
/// @brief implements particle hpp clases 


#include "../Headers/Particle.hpp"
#include "../Headers/Scene.hpp"
namespace misi
{
    Particle::Particle(btVector3 given_rotation, float given_mass,
        btVector3 given_inertia, float given_restitution, ObjectType given_type, btVector3 given_origin,
        btVector3 given_size, btVector3 given_velocity, float given_lifeSpam, shared_ptr<Scene> given_world, int x)
    {
        Maxvelocity = given_velocity;
        velocity = Maxvelocity;
        particleSize = given_size;
        maxSpam = given_lifeSpam;
        lifeSpam = maxSpam;
        worldReference = given_world;
        body = make_shared <PhysicSphere>(given_rotation, given_mass, given_inertia,  given_restitution, given_type, given_origin);

        SetId(x);
        GetBody()->SetName(GetId());
        body->Getbody()->setCollisionFlags(body->Getbody()->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
        worldReference->addModel(body);
        

    }

    void Particle::Reset()
    {
        lifeSpam = maxSpam;
        float min_offset = -0.1f; // Define the minimum offset value
        float max_offset = 0.1f; // Define the maximum offset value

        // Generate random offsets between min_offset and max_offset
        float random_offset_x = min_offset + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max_offset - min_offset);
        float random_offset_z = min_offset + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max_offset - min_offset);

        float random_offset_t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * maxSpam;


        btVector3 random(random_offset_x, 0, random_offset_z);

        velocity = velocity + random;

        velocity *= -1;

        lifeSpam = random_offset_t;

       
    }
    void Particle::Reactivate()
    {
        Reset();
    }



    void Particle::Deactivate()
    {
        Reset();
    }

    void Particle::MoveParticle(btVector3(velocity))
    {
        body->DisableGravity();
        body->Getbody()->setLinearVelocity(velocity);
    }
   
}
