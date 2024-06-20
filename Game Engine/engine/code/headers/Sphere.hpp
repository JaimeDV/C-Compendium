/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief contains definitions and classes for a math sphere

#pragma once
#include "Point.hpp"
#include "Math.hpp"
#include "Plane.hpp"

namespace misi
{
	class Sphere
	{
		Point3 center;
		float radius;

	public:

		bool intersects(const Sphere& other)
		{
			return Distance(this->center, other.center) < this->radius + other.radius;
		}

		//only for floats i don't know if this is the best aproach
		bool intersect(const Plane<float>& other)
		{

		}

		bool intersect(const Sphere& other)
        {

		}

		//falta intersect plane y intersect sphere
	};
}