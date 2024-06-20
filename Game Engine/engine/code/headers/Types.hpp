/// @copyright � 2023+ Jaime d�az vi�itez
/// @author Author: Jaime D�az Vi�itez
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