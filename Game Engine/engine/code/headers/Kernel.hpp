/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 26/12/2023
/// @brief Defines Kernel classes
#pragma once

#include <queue>
#include <list>
#include "Message.hpp"
using namespace std;
namespace misi
{
	class Task;
	class Kernel //al instanciarse puede buscar dll de un archivo e instanciar las dll que esten dentro
	{
		/*struct Task_wrapper //un used
		{
			Task* task;
			bool operator < (const Task_wrapper& other) const
			{
				return *this->task < *other.task;
			}
		};*/
		Message_Dispacher* dispacher;
		std::list<Task*> tasks; //queue en vez de lista para poder poner prioridades
		bool exit;
	public:

		Kernel()
		{
			dispacher = nullptr;
			exit = false;
		}
		void add(Task** task)
		{
			tasks.push_front(*task);
		}
		void set_exit(bool value)
		{
			exit = value;
		}
		void set_dispacher(Message_Dispacher* given_value)
		{
			dispacher = given_value;
		}
		Message_Dispacher* get_dispacher()
		{
			return dispacher;
		}
		void run();
		void stop()
		{
			exit = true;
		}
	};
}