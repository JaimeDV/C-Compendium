/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 03/03/2024
#pragma once


#include "MultiShapeObject.hpp"
#include "Message.hpp"
#include "vector"
namespace misi
{
	class Scene;

	/// @brief Encapsulation of the physical model & behaviour of the moving car inside scene
	class Car : public Message_Listener
	{
		Scene* fatherScene;
		MultiShapeObject* carPointer;
		MultiShapeObject* carClawPointer;
		vector<physicBody*> car;
		bool retractedClaw = false;

		~Car();
		public:

		Car(Scene* given_Scene);
		/// @brief Parses all the messages that matches the listener id
		/// @param Message message send
		virtual void handle(const Message& message) override;

		/// @brief Sets the tourge value of the claw to the parameter. This funtion is not called when creating a car.
		/// @param value amount of touge to add, 75 is a good value if in doubt
		void SetClawTourge(float value)
		{
			carClawPointer->SetTorque(value);
		}
		/// @brief Sets the tourge value of the car wheels to the parameter. This funtion is not called when creating a car.
		/// @param value amount of touge to add, 75 is a good value if in doubt
		void SetCarTourge(float value)
		{
			carPointer->SetTorque(value);
		}
		/// @brief Sets the speed value of the claw like touge its not called when creating a new car
		/// @param value amount of speed to add,negative values equal right movements,  left positive
		void SetClawSpeed(float value)
		{
			carClawPointer->AddSpeed(value);
		}
		/// @brief Sets the speed value of the car wheels like touge its not called when creating a new car
		/// @param value amount of speed to add,negative values equal right movements, left positive
		void SetCarSpeed(float value)
		{
			carPointer->AddSpeed(value);
		}
		/// @brief Resets all the variable of the car to the state they where when created bu the constructor
		void Reset();
	};
}