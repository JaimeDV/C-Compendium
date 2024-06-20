/// @copyright � 2023+ Jaime d�az vi�itez
/// @author Author: Jaime D�az Vi�itez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief defines functions to create pseudo randon numbers using xorshift
#pragma once

#include "Types.hpp"

namespace misi
{
	template<typename TYPE>
	class XorShift {
		TYPE seed;

		XorShift(typename& value) {
			seed = value;
		}

	public:
		//generates the randon mumber using the seed
		typename next() {
			seed ^= seed << 13;
			seed ^= seed >> 17;
			seed ^= seed << 5;
			return seed;
		}
	};
}

//	//template<>
//
//	//TO Do Make Template Version
//
//	class XorShift //para numeros de 32 bits , son m�s rapidos
//	{
//		uint32_t seed;
//
//		XorShift(uint32_t value) {
//			seed = value;
//		}
//
//	public:
//		//generates the randon mumber using the seed
//		uint32_t next() {
//			seed ^= seed << 13;
//			seed ^= seed >> 17;
//			seed ^= seed << 5;
//			return seed;
//		}
//	};
//	/*public:
//		XorShift(int seed) {
//		}
//		uint32_t next() {
//			return 0;
//		}
//	};*/
//}
}