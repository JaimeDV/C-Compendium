/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 03/03/2024

#pragma once
#include "MultiShapeObject.hpp"
#include "Message.hpp"
namespace misi
{
	class Scene;
	/// @brief Encapsulation of the physical model & behaviour of the game background
	class BackGround : public Message_Listener
	{
		Scene* fatherScene;
		MultiShapeObject* ClawPointer;
		~BackGround();
	public:

		PhysicPolygon* movingPlataform;
		BackGround(Scene* given_Scene);

		/// @brief Parses all the messages that matches the listener id
		/// @param Message message send
		virtual void handle(const Message& message) override;

		/// @brief Sets the tourge value of the claw to the parameter. This funtion is not called when creating a car.
		/// @param value amount of touge to add, 75 is a good value if in doubt
		void SetClawTourge(float value)
		{
			ClawPointer->SetTorque(value);
		}
		/// @brief Sets the speed value of the claw like touge its not called when creating a new car
		/// @param value amount of speed to add,negative values equal right movements,  left positive
		void SetClawSpeed(float value)
		{
			ClawPointer->AddSpeed(value);
		}

		/// @brief Spawns the raising plataform on top of the void
		void putPlataform()
		{
			movingPlataform->getBody()->SetTransform(b2Vec2(5, 2.4f), movingPlataform->getBody()->GetAngle());
		}

		/// @brief changes the plataform position based on the raise value until it hits the limit
		/// @param raisevalue amount of movement per tick
		/// @param limit maximun y value the plataform can have
		void raisePlataform(float raiseValue, float limit)
		{
			if (movingPlataform->getBody()->GetPosition().y < limit)
			{
				movingPlataform->getBody()->SetTransform(movingPlataform->getBody()->GetPosition()+ b2Vec2(0, raiseValue),
					movingPlataform->getBody()->GetAngle());
			}
		}
	};
}

