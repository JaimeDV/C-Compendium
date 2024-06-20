/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 02/03/2024



#include <Box2D/Box2D.h>
#include <map>
#include <string>
#include "Message.hpp"
#pragma once
namespace misi
{
	/// @brief class that overwrites box2dContactlistener to send b2body contact info to the message system
	class CollisionListener : public b2ContactListener //solo me preocupo por triggers, son los unicos que colisionaran
	{
		Message_Dispacher* message_dispacher;
		std::map< b2Body*, std::string > Listeners ;//not optimal but i can't find a better alternative at the moment

		/// @brief overwrite of the box2d BeginContact funtion, checks when a collision happens and if they are from listeners
		/// @param contact box2d contanct info
		void BeginContact(b2Contact* contact) override;

		/// @brief overwrite of the box2d EndContact funtion, checks when a collision ends and if they are from listeners
		/// @param contact box2d contanct info
		void EndContact(b2Contact* contact) override;
	public:

		//can't be higher that 16 layers
		enum colisionLayer :uint16_t
		{
			ground = 1,
			wall = 2,
			backGround = 4,
			trigger = 8,
			particle = 16,
			player = 32,
		};


		/// @brief Adds a box2d listener to the map, object that are not listeners are not considered when handling colisions
		/// @param body box2dBody to add to the list, 
		/// @param code unique indentifier to know what to do when colliding with said body
		void addListener(b2Body* body, std::string code)
		{
			Listeners.insert(std::make_pair(body, code));
		}

		CollisionListener(Message_Dispacher* given_message_dispacher)
		{
			 message_dispacher= given_message_dispacher;
		}

	};

	
}