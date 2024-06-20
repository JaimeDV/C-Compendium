/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 03/01/2023
/// @brief Defines and playercontroller class that recives and send messages relevant to the player
#pragma once

#include "Message.hpp"
namespace misi
{
	class player_controller : public Message_Listener
	{
		Message_Dispacher* message_dispacher;

		public:
			player_controller(Message_Dispacher* dispacher)
			{
				message_dispacher = dispacher;
			}
			Message_Dispacher* get_dispacher()
			{
				return message_dispacher;
			}
			virtual void handle(const Message& message) override; //declared in the game
	};
}