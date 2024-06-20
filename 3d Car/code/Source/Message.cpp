/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 30/12/2023
/// @brief implments themethods defined in message.hpp

#include "../headers/Message.hpp"
#include "../Headers/Door.hpp"
namespace misi
{
	Message_Dispacher::Message_Dispacher(std::shared_ptr<Scene> given_owner)
	{
		owner =given_owner;

	}

	Message_Dispacher::Message_Dispacher(std::shared_ptr<Door> given_owner)
	{
		ownerB = given_owner;

	}

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