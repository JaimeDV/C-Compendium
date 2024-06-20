/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief Ensures that some types are allways defined, to ensure older c++ can copilate the code

#pragma once

#include <cstdlib>
#include <cstdint>
#include "Macros.hpp"

namespace misi
{
#if not defined ENGINE_CPP_17_AVATIBLE

	enum byte :uint8_t
	{
	};
#else
	using byte = std::byte; //falta meter la macro
#endif
}