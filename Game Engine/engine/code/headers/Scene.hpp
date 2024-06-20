/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 26/12/2023
/// @brief Defines scene classes that holds the kernel loop
#pragma once
#include <string> 
#include "Window.hpp"
#include "PlayerController.hpp"
using namespace std;
namespace misi
{
	class Kernel;
	class Scene
	{
		Kernel * kernel;
		Message_Listener* message_Listener;//cambiar bool por clase, no esta en el constructor
		string scene_name;
		player_controller* player;
	public:

		Scene(string name, unsigned width, unsigned height, bool full_screen = true);
		Scene(string name, unsigned x, unsigned y, unsigned width, unsigned height);
		Message_Listener* get_message_Listener()//cambiar por mesage 
		{
			return message_Listener;
		}
		player_controller* get_player()
		{
			return player;
		}
		void run();
	};
}