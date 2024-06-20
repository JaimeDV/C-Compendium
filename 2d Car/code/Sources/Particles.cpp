/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024
/// @brief implements particle hpp clases 

#include "../Headers/Particle.hpp"

namespace misi
{
    Particle::Particle(Vector2f given_position, Vector2f given_size, shapeType given_shape,
        Vector2f given_velocity, float given_lifeSpam,physicWorld* given_world)
    {
        position = given_position;
        particleShape = given_shape;
        Maxvelocity = given_velocity;
        velocity = Maxvelocity;
        particleSize = given_size;
        active = 0;
        maxSpam = given_lifeSpam;
        lifeSpam = maxSpam;
        particleColor = new Color(rand() % 1 + 255, rand() % 1 + 255, rand() % 1 + 255, 1);
        world = given_world;
        GenerateShape();

    }

    void Particle::Reset()
    {
        lifeSpam = maxSpam;
        float min_offset = -0.01f; // Define the minimum offset value
        float max_offset = 0.01f; // Define the maximum offset value

        // Generate random offsets between min_offset and max_offset
        float random_offset_x = min_offset + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max_offset - min_offset);


        float random_offset_t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * maxSpam;
        float random_offset_y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * Maxvelocity.y;
        sfmShape->getBody()->SetTransform(b2Vec2(position.x, position.y), sfmShape->getBody()->GetAngle());
        velocity = Vector2f(Maxvelocity.x + random_offset_x, Maxvelocity.y + random_offset_y);
        lifeSpam = random_offset_t;
        sfmShape->getBody()->SetEnabled(true);
    }

    void Particle::GenerateShape()
    {

        //CircleShape* circleShape = nullptr;
        //RectangleShape* rectangleShape = nullptr;
        float random_offset_x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float random_offset_y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        switch (particleShape)
        {
        case Shapesphere:
           /* circleShape = new CircleShape(particleSize.x);
            circleShape->setFillColor(*particleColor);
            circleShape->setPosition(position);
            circleShape->setScale(particleSize);*/
           
            sfmShape = new PhysicSphere(b2Vec2(position.x+ random_offset_x, position.y+random_offset_y), b2_dynamicBody, 0, 0, 0, 0, world,
                particleSize.x, false, CollisionListener::particle, 0);
            sfmShape->getBody()->SetEnabled(false);
            break;
        case Shaperectangle:
         /*   rectangleShape = new RectangleShape(particleSize);
            rectangleShape->setFillColor(*particleColor);
            rectangleShape->setPosition(position);
            rectangleShape->setScale(particleSize);*/
            break;
        case  Shapepolygon:
            //to code
            break;
        case ShapeconvexPolygon:
            //to code
            break;
        case ShapeLine:
            //to code
            break;
        default:
            sfmShape = nullptr;
        }
    }

   
}
