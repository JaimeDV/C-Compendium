/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 25/02/2024


#include "box2d/box2d.h"
#include "Windows.h"
#include "SFML/Graphics.hpp"
#include "World.hpp"
#pragma once

using namespace sf;
namespace misi
{
	/// @brief class that renders 2bBodys using the sfm library
	class Renderer
	{
		b2World& world;
		RenderWindow& window;
		float scale;
		float window_height;
	public:

		Renderer(physicWorld& givenWorld, RenderWindow& givenWindow, float givenScale);

		/// @brief parses all the box2dobjects in the world & renders then to the window
		void Render();
		/// @brief changes the positions of the bodys so it is consistent with the sfml format
		inline Vector2f box2dPositionToSfmlPosition(const b2Vec2& box2d_position, float window_height, float scale)
		{
			return Vector2f(box2d_position.x * scale, window_height - box2d_position.y * scale);
		}

	};
}