/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief defines the point class and the relevant methods

#pragma once

namespace misi
{
	//falta especializaon de 2 y 3
	template<unsigned Dimension, typename TYPE>
	struct Point
	{
		TYPE coordinates[Dimension];
	};
	using Point4 = Point<4, float>;
	using Point3 = Point<3, float>;
	using Point2 = Point<2, float>;
}