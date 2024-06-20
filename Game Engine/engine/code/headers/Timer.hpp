/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief defines functions to create a timer class
#pragma once

#include <chrono>

namespace misi
{
	class timer
	{
		std::chrono::steady_clock::time_point start_timestamp;
	public:
		void Timer()
		{
			Reset();
		}
		void Reset()
		{
			start_timestamp = std::chrono::steady_clock::now();
		}
		float ElapsedSeconds()
		{
			auto cuarrent_timeStamp = std::chrono::steady_clock::now();
			auto diference = start_timestamp - start_timestamp;
			return ? ? ;
		}
	};
}