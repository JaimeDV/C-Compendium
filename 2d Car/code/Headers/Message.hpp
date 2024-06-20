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
namespace misi
{
	class Scene;
	using parameter = float; //removed variant due o byte incompatibility when upgrading to c++17

	/// @brief message compement sent trought the message system, it allows up to 3 parameters, the first one being always the id
	struct Message
	{
		std::string id; 
		std::map<std::string, parameter> parameters;
		std::map<std::string, std::pair<parameter, parameter>> double_parameters;
		Message(std::string id, std::map<std::string, parameter> parameters);
		Message(std::string id, std::map<std::string, std::pair<parameter, parameter>> double_parameters);
		void set_id(std::string given_id)
		{
			id = given_id;
		}
		void set_params(std::map<std::string, parameter> given_param)
		{
			parameters = given_param;
		}
		void set_params(std::map<std::string, std::pair<parameter, parameter>> given_param)
		{
			double_parameters = given_param;
		}
	};

	/// @brief abstract class used to listen messages from the message server
	class Message_Listener//tienen que hereralo 
	{
	public:
		/// @brief Parses all the messages that matches the listener id
		/// @param Message message send
		virtual void handle(const Message& message) = 0;
	};

	/// @brief Sends messages to all listener 
	class Message_Dispacher
	{
		std::list<Message> messages;
		std::map< std::string, std::list<Message_Listener*>> messageListeners;
		Scene* owner;
	public:

		Message_Dispacher(Scene* given_owner);

		void send(const Message& message) {
			messages.push_back(message);
		}
		void add(Message_Listener& listener, const std::string& message_id) {
			messageListeners[message_id].push_back(&listener);
		}
		/// @brief for each message iterates asking the listener to handle the message
		///  "normaly check if its relevant to then and if that is the case doing something"
		/// @param float unused, frame time
		bool execute(float t);
	};
}
