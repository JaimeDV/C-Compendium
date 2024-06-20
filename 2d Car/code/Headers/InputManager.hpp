/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 14/12/2023

#pragma once

#include "SFML/Graphics.hpp"
#include "Message.hpp"
#include <assert.h>
#include <string>
#include <map>

namespace misi
{
	using namespace sf;
	class Scene;

	/// @brief using sfml reads the players input & sends messages trought the message system
	class InputManager : public Message_Listener
	{
		bool exit;
		Message_Dispacher* message_dispacher;
		RenderWindow* window;
		Scene* fatherScene;
	public:

		InputManager(RenderWindow* given_window, Scene* given_scene)
		{
			exit = false;
			window = given_window;
			message_dispacher = nullptr;
			fatherScene = given_scene;
		}
		Message_Dispacher* get_message_dispacher()
		{
			return message_dispacher;
		}
		void set_message_dispacher(Message_Dispacher* given_dispacher)
		{
			message_dispacher = given_dispacher;
		}

		/// @brief begins the key listen loop, closes when the game window is closed
		void Run();

		/// @brief Sends an apropiate message based on the given key, some keys are unimplemented at the moment
		/// @param key keycode value of the key pressed
		void handleKeyPress(sf::Keyboard::Key key);

		/// @brief Parses all the messages that matches the listener id
		/// @param Message message send
		virtual void handle(const Message& message) override;
	};
}