/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 20/04/2024
/// @brief defines multiples variables used to render 3d models
#pragma once
#include <vector>
#include "math.hpp"
#include "colorBuffer.hpp"
#include "Rasterizer.hpp"

using  std::vector;
using argb::Rgb888;
using argb::Color_Buffer;
namespace misi
{

	typedef Rgb888                Color;
	typedef argb::Color_Buffer< Color > Color_Buffer;
	typedef math::Point4f               Vertex;
	typedef vector< Vertex >      Vertex_Buffer;
	typedef vector< int    >      Index_Buffer;
	typedef vector< Color  >      Vertex_Colors;
	

}