/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief defines helpfull mat options for the engine and definition for common math types

#pragma once

#include "glm/glm.hpp"
#include <cmath>
#include <limits>

namespace misi
{
	using Vector2 = glm::vec2;
	using Vector3 = glm::vec3; //se podria meter en un cabezera math.hpp
	using Vector4 = glm::vec4;

	using Matrix33 = glm::mat3;
	using Matrix44 = glm::mat4;

	using DoubleQuaternion = glm::dquat;
	using FloatQuaternion = glm::fquat;
	using Quaternion = glm::quat;

	template<typename OBJECT_A, typename OBJECT_B>
	float Distance(const OBJECT_A& object_a, const OBJECT_B& object_b); //especializarlo en point
}