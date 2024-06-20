/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
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
//	class XorShift //para numeros de 32 bits , son más rapidos
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