//here we implement input manager functon to avoid using
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 14/12/2023
/// @brief contains implementations of the classes in inputManager.Hpp
#include "../headers/InputManager.hpp"
namespace misi
{

    void InputManager::handleKeyPress(sf::Keyboard::Key key) {
        std::map<std::string, parameter> parameters;
        Message input_message("Player", parameters);
        misi::parameter param(0);
        if (key == sf::Keyboard::A)
        {

            input_message.set_id("Scene");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("A"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }

        if (key == sf::Keyboard::D)
        {
            input_message.set_id("Scene");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("D"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }

        if (key == sf::Keyboard::W)
        {
            input_message.set_id("Scene");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("W"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }

        if (key == sf::Keyboard::S)
        {
            input_message.set_id("Scene");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("S"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }


        if (key == sf::Keyboard::E)
        {
            input_message.set_id("Scene");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("E"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }

        if (key == sf::Keyboard::Q)
        {
            input_message.set_id("Scene");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("Q"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }
          
    }

    
};