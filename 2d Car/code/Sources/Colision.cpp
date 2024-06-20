/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 02/03/2024
/// @brief class that implements collision.hpp clases

#include "../Headers/Collision.hpp"
namespace misi
{
	void CollisionListener::BeginContact(b2Contact* contact)
	{
        misi::parameter param(0);
		std::map<std::string, parameter> parameters;
		Message input_message("Player", parameters);
		b2Body* bodyUserData = contact->GetFixtureA()->GetBody();
		auto pos = Listeners.find(bodyUserData);
		if (pos != Listeners.end())
		{
			std::string listenerValue = pos->second;
			if (pos->second == "void Trigger")
			{
				input_message.set_id("Player");
				parameters.clear();
                parameters.insert(std::make_pair(std::string("Reset"), param));
				input_message.set_params(parameters);
				message_dispacher->send(input_message);
			}
			if (pos->second == "Crate Trigger")
			{
				input_message.set_id("Turret");
				parameters.clear();
                parameters.insert(std::make_pair(std::string("spin"), param));
				input_message.set_params(parameters);
				message_dispacher->send(input_message);
			}
			if (pos->second == "Plataform")
			{
				input_message.set_id("Scene");
				parameters.clear();
                parameters.insert(std::make_pair(std::string("raise Plataform"), param));
				input_message.set_params(parameters);
				message_dispacher->send(input_message);
			}
			if (pos->second == "Particle Trigger")
			{
				input_message.set_id("particle");
				parameters.clear();
                parameters.insert(std::make_pair(std::string("start Emision"), param));
				input_message.set_params(parameters);
				message_dispacher->send(input_message);
			}

		}
		else
		{
			bodyUserData = contact->GetFixtureB()->GetBody();
			auto pos = Listeners.find(bodyUserData);
			if (pos != Listeners.end())
			{
				std::string listenerValue = pos->second;
				if (pos->second == "void Trigger")
				{
					input_message.set_id("Player");
					parameters.clear();
                    parameters.insert(std::make_pair(std::string("Reset"), param));
					input_message.set_params(parameters);
					message_dispacher->send(input_message);

				}
				if (pos->second == "Crate Trigger")
				{
					input_message.set_id("Turret");
					parameters.clear();
                    parameters.insert(std::make_pair(std::string("spin"), param));
					input_message.set_params(parameters);
					message_dispacher->send(input_message);
				}
				if (pos->second == "Plataform")
				{
					
					input_message.set_id("Scene");
					parameters.clear();
                    parameters.insert(std::make_pair(std::string("raise Plataform"), param));
					input_message.set_params(parameters);
					message_dispacher->send(input_message);
				}
				if (pos->second == "Particle Trigger")
				{
					input_message.set_id("particle");
					parameters.clear();
                    parameters.insert(std::make_pair(std::string("start Emision"), param));
					input_message.set_params(parameters);
					message_dispacher->send(input_message);
				}
			}
		}
	}

	void CollisionListener::EndContact(b2Contact* contact)
	{
        misi::parameter param(0);
		std::map<std::string, parameter> parameters;
		Message input_message("Player", parameters);
		b2Body* bodyUserData = contact->GetFixtureA()->GetBody();
		auto pos = Listeners.find(bodyUserData);
		if (pos != Listeners.end())
		{
			std::string listenerValue = pos->second;
			
			if (pos->second == "Plataform")
			{
				input_message.set_id("Scene");
				parameters.clear();
				parameters.insert(std::make_pair(std::string("Stop Plataform"), param));
				input_message.set_params(parameters);
				message_dispacher->send(input_message);
			}

		}
		else
		{
			bodyUserData = contact->GetFixtureB()->GetBody();
			auto pos = Listeners.find(bodyUserData);
			if (pos != Listeners.end())
			{
				std::string listenerValue = pos->second;
				if (pos->second == "Plataform")
				{
					input_message.set_id("Scene");
					parameters.clear();
					parameters.insert(std::make_pair(std::string("Stop Plataform"), param));
					input_message.set_params(parameters);
					message_dispacher->send(input_message);
				}
			}
		}

		auto body2 = contact->GetFixtureB();
	}

}