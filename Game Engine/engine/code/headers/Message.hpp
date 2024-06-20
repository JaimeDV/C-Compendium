/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 30/12/2023
/// @brief Defines and observer class to send messages between player & engine 
#pragma once

#include <map>
#include <list>
#include <string>
#include <vector>
#include <variant>
#include "Task.hpp"
namespace misi 
{
	using parameter = std::variant<int, float, std::string, std::vector<int>, std::vector<float> >; //poner aqui entre comas que tipos de parametros podemos querer in, string,
	struct Message 
	{
		std::string id; //estaria bien cambiarlos por hash
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

	class Message_Listener//tienen que hereralo 
	{
		public:
			virtual void handle(const Message& message) = 0;
	};

	class Message_Dispacher:Task
	{
		std::list<Message> messages;
		std::map< std::string, std::list<Message_Listener*>> messageListeners;

	public:

		Message_Dispacher(Scene* given_owner);

		void send(const Message& message) {
			messages.push_back(message);
		}
		void add(Message_Listener& listener, const std::string& message_id) {
			messageListeners[message_id].push_back(&listener);
		}
		bool execute(float t) override;//esto podria estar en send en vez de ser una task
	};

	//mesaje example //esto es solo de ejemplo
	//    void key_presed(int_keycode)
	//{
	//}

	//class enemy : public game object, public mesagelistener //ejemplo de uso de handeler
	//{
	//public:
	//    void Handle(mensaje)
	//        if(Message.id==...)
	//};

	//while (poll_event(event))
	//{
	//    switch (event.type)
	//    {
	//        case key pressed:
	//            if (event.key.code == Key_Space) //ojo esto estaria dentro del motor o
	//                                            //que input genere evnetos de hardware concreto y que el juego los use para sacar eventos
	//                                            // la mejor que fuera considerable input task para decirle que eventos de inputs concretos
	//                                            // es decir que el juego diga espacio = jump y el imput manager mirando un diccionario genere
	//                                            // un evento jump cuando de space
	//            {
	//                //es decir aqui mandaria en jump
	//
	//                Messaje jump{"jump" } //esta seria la implentación que quiere, el jugador deberia ser un listener de jump
	//                key_pressed.parameters["key-code"] = event.key.code;
	//                scene.get_message_dispacher ().send(pressed) //manda el mensaje creado encima
	//            }
	//            break;
	//    }
	//}

	//solucion mala (en juego)

	//    class input handler {
	//    void handle
	//    {
	//        if message id == keypressed
	//        {
	//            switch (Message.paramerters["key-code"].get<int>())
	//            {
	//                case ----
	//                    kessahe
	//                    scene.get dispacher
	//            }
	//        }
	//
	//    }
	//};
}