/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 30/12/2023
/// @brief implments themethods defined in message.hpp

#include "../headers/Task.hpp"
#include "../headers/Message.hpp"
namespace misi
{
	Message_Dispacher::Message_Dispacher(Scene* given_owner):Task()
	{
		set_consumable(false);
		task_name = "MesageTask";
		set_owner(given_owner);

	}
	
	/// @brief for each message iterates asking the listener to handle the message
	///  "normaly check if its relevant to then and if that is the case doing something"
	/// @param float unused, frame time
	bool Message_Dispacher::execute(float t)
	{
		auto it = messages.begin();
		while (it != messages.end())
		{
			auto& Message = *it;
			auto& listeners = messageListeners[Message.id];

			for (auto& listener : listeners)
			{
				listener->handle(Message);
			}

			// Remove the message after handling
			it = messages.erase(it);
		}

		return false;
	}
	Message::Message(std::string given_id, std::map<std::string, parameter> given_parameters)
	{
		id = given_id;
		parameters = given_parameters;
	}
	Message::Message(std::string given_id, std::map<std::string, std::pair<parameter, parameter>> given_parameters)
	{
		id = given_id;
		double_parameters = given_parameters;
	}
}