/// @copyright � 2023+ Jaime d�az vi�itez
/// @author Author: Jaime D�az Vi�itez
/// pamecin@gmail.com
/// @date 14/12/2023
/// @brief Manages the main Input Loop
#pragma once

#include <SDL.h>
#include "Message.hpp"
namespace misi
{
#define Quit SDL_QUIT

	class InputManager: public Message_Listener
	{
		bool exit;
		Message_Dispacher* message_dispacher;
	public:

		InputManager()
		{
			exit = false;
		}
		Message_Dispacher* get_message_dispacher()
		{
			return message_dispacher;
		}
		void set_message_dispacher(Message_Dispacher* given_dispacher)
		{
			message_dispacher = given_dispacher;
		}
		void Update();
		virtual void handle(const Message& message) override;
	};
}