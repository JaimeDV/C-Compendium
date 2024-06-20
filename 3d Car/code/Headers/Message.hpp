/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 30/12/2023
#pragma once

#include <map>
#include <list>
#include <string>
#include <vector>
#include <variant>
#include <memory>
namespace misi
{
    class Scene;
    class Door;

    // Removed variant due to byte incompatibility when upgrading to C++17
    using parameter = float;

    /// @brief Message complement sent through the message system, it allows up to 3 parameters, the first one being always the id
    struct Message
    {
        std::string id; // Identifier of the message
        std::map<std::string, parameter> parameters; // Map of parameters
        std::map<std::string, std::pair<parameter, parameter>> double_parameters; // Map of double parameters

        /// @brief Constructor for Message with single parameters
        /// @param id Identifier of the message
        /// @param parameters Map of parameters
        Message(std::string id, std::map<std::string, parameter> parameters);

        /// @brief Constructor for Message with double parameters
        /// @param id Identifier of the message
        /// @param double_parameters Map of double parameters
        Message(std::string id, std::map<std::string, std::pair<parameter, parameter>> double_parameters);

        /// @brief Set the ID of the message
        /// @param given_id The ID to set
        void set_id(std::string given_id)
        {
            id = given_id;
        }

        /// @brief Set the single parameters of the message
        /// @param given_param The parameters to set
        void set_params(std::map<std::string, parameter> given_param)
        {
            parameters = given_param;
        }

        /// @brief Set the double parameters of the message
        /// @param given_param The double parameters to set
        void set_params(std::map<std::string, std::pair<parameter, parameter>> given_param)
        {
            double_parameters = given_param;
        }
    };

    /// @brief Abstract class used to listen messages 
    class Message_Listener
    {
    public:
        /// @brief Parses all the messages that match the listener ID
        /// @param message The message received
        virtual void handle(const Message& message) = 0;
    };

    /// @brief Sends messages to all listeners 
    class Message_Dispacher
    {
        std::list<Message> messages; // List of messages
        std::map < std::string, std::list<std::shared_ptr<Message_Listener>>> messageListeners; // Map of message listeners
        std::shared_ptr<Scene> owner; // Pointer to the scene owner
        std::shared_ptr<Door> ownerB; // Pointer to the door owner

    public:

        /// @brief Constructor for Message_Dispacher with a scene owner
        /// @param given_owner Pointer to the scene owner
        Message_Dispacher(std::shared_ptr<Scene> given_owner);

        /// @brief Constructor for Message_Dispacher with a door owner
        /// @param given_owner Pointer to the door owner
        Message_Dispacher(std::shared_ptr<Door> given_owner);

        /// @brief Send a message
        /// @param message The message to send
        void send(const Message& message) {
            messages.push_back(message);
        }

        /// @brief Add a message listener
        /// @param listener The listener to add
        /// @param message_id The ID of the message
        void add(std::shared_ptr<Message_Listener> listener, const std::string& message_id) {
            messageListeners[message_id].push_back(listener);
        }

        /// @brief Execute message handling for each message
        /// @param t Unused, frame time
        /// @return True if executed successfully
        bool execute(float t);
    };
}