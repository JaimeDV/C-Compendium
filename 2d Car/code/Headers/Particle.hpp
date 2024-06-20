/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024
#pragma once

#include "box2d/box2d.h"
#include "Windows.h"
#include "SFML/Graphics.hpp"
#include "World.hpp"
#include <vector>
#include  "MultiShapeObject.hpp"
#include "Collision.hpp"

using namespace sf;


namespace misi
{
     enum shapeType
     {
        Shapesphere,
        Shaperectangle,
        Shapepolygon,
        ShapeconvexPolygon,
        ShapeLine
     };



     /// @brief Encapsulates the particles emited by the particle system, should 
     ///use sfml shapes but due to errors with the render system has box2d body. 
    struct Particle
    {
        Vector2f position;
        Vector2f particleSize;
        Vector2f Maxvelocity;
        Vector2f velocity;
        float lifeSpam;
        float maxSpam;
        UINT32 active; //bool is not used to ensure a consistent byte size 
        Color* particleColor;
        physicWorld* world;
        Particle(Vector2f given_position, Vector2f given_size, shapeType given_shape, 
            Vector2f given_velocity, float given_lifeSpam, physicWorld* given_world);
        physicBody* getShape()
        {
            return sfmShape;
        }
        /// @brief moves the particle position following the given speed vector
        /// @param velocity amount of movement made in one game tick
        void moveparticle(Vector2f (velocity))
        {
                sfmShape->getBody()->SetTransform(sfmShape->getBody()->GetPosition() + b2Vec2(velocity.x, velocity.y),
                sfmShape->getBody()->GetAngle());
        }
        
        /// @brief resets all the particle values and adds a little of randomness to the position.
        void Reset();

        //unsued
        void Deactivate()
        {
            active = 0;
        }
        //unsued
        void Reactivate()
        {
            active = 1;
        }

        private:
        shapeType particleShape;
        physicBody* sfmShape;
        /// @brief using the given shape type sets the value of sfmShapoe to be the corresponding shape, 
        /// due to errors only spehere is implemened
        void GenerateShape();
        ~Particle()
        {
            delete particleColor;
            delete sfmShape;
        }
    };

}

