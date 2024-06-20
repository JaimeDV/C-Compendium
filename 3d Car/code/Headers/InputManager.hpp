/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 14/12/2023

#pragma once

#include "SFML/Graphics.hpp"
#include "Message.hpp"
#include <assert.h>
#include <map>
namespace misi
{
    /// @brief Using SFML, reads the player's input and sends messages through the message system
    class InputManager
    {
        std::shared_ptr<Message_Dispacher> message_dispacher; // Shared pointer to the Message_Dispacher object

    public:
        /// @brief Default constructor initializing message dispatcher to nullptr
        InputManager()
        {
            message_dispacher = nullptr;
        }

        /// @brief Constructor initializing the message dispatcher with a given dispatcher
        /// @param given_dispacher Shared pointer to the Message_Dispacher object
        InputManager(std::shared_ptr<Message_Dispacher> given_dispacher)
        {
            message_dispacher = given_dispacher;
        }

        /// @brief Retrieves the current message dispatcher
        /// @return Shared pointer to the Message_Dispacher object
        std::shared_ptr<Message_Dispacher> get_message_dispacher()
        {
            return message_dispacher;
        }

        /// @brief Sets the message dispatcher to the given dispatcher
        /// @param given_dispacher Shared pointer to the Message_Dispacher object
        void set_message_dispacher(std::shared_ptr<Message_Dispacher> given_dispacher)
        {
            message_dispacher = given_dispacher;
        }

        /// @brief Sends an appropriate message based on the given key. Some keys are unimplemented at the moment.
        /// @param key Keycode value of the key pressed
        void handleKeyPress(sf::Keyboard::Key key);
    };
}