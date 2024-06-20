/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 07/03/2024

#pragma once
#include "ParticlePool.hpp"
namespace misi
{
    /// @brief draws each particle in the window, unsued due to the renderbug
    class ParticleRenderer
    {
        ParticlePool* particlePool;
        RenderWindow* window;

    public:
        void Render();
        ParticleRenderer(ParticlePool* given_particlePool,RenderWindow* given_window)
        {
            particlePool = given_particlePool;
            window = given_window;
        }
        inline Vector2f box2dPositionToSfmlPosition(const b2Vec2& box2d_position, float window_height, float scale)
        {
            return Vector2f(box2d_position.x * scale, window_height - box2d_position.y * scale);
        }
    };
}