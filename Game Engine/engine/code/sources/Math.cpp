/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief defines helpfull mat functions for the engine

#include "../headers/Math.hpp"
#include "../headers/Point.hpp"
//#include "../headers/Plane.hpp"
//#include "../headers/Sphere.hpp"

namespace misi {
	template<>
    //Missing calculate collision

	/// @brief calculates the distance between 2 3d points
	/// @param PointA the first point
	/// @param PointB the second point
	/// @returns the distance between the 2 points
	float Distance(const Point3& pointA, const Point3& pointB)
	{
		float delta_x = pointB.coordinates[0] - pointA.coordinates[0];
		float delta_y = pointB.coordinates[1] - pointA.coordinates[1];
		float delta_z = pointB.coordinates[2] - pointA.coordinates[2];

		return sqrt(delta_x * delta_x + delta_y * delta_y + delta_z * delta_z);
	}

	/// @brief calculates the distance between 2 2d points
	/// @param PointA the first point
	/// @param PointB the second point
	/// @returns the distance between the 2 points
	float Distance(const Point2& pointA, const Point2& pointB)
	{
		float delta_x = pointB.coordinates[0] - pointA.coordinates[0];
		float delta_y = pointB.coordinates[1] - pointA.coordinates[1];
		return sqrt(delta_x * delta_x + delta_y * delta_y);
	}

	/// @brief calculates the distance between 2 4d points
	/// @param PointA the first point
	/// @param PointB the second point
	/// @returns the distance between the 2 points
	float Distance(const Point4& pointA, const Point4& pointB)
	{
		float delta_x = pointB.coordinates[0] - pointA.coordinates[0];
		float delta_y = pointB.coordinates[1] - pointA.coordinates[1];
		float delta_z = pointB.coordinates[2] - pointA.coordinates[2];
		float delta_w = pointB.coordinates[3] - pointA.coordinates[3];
		return sqrt(delta_x * delta_x + delta_y * delta_y + delta_z * delta_z + delta_w * delta_w);
	}
}