//here we implement input manager functon to avoid using
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 14/12/2023
/// @brief contains implementations of the classes in inputManager.Hpp
#include "../headers/InputManager.hpp"
#include "../headers/Message.hpp"
#include "../Headers/Scene.hpp"
namespace misi
{

    void InputManager::Run() {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
            window->close();
            exit = true;
            fatherScene->exit();
            }
            else if (event.type == sf::Event::KeyPressed) 
            {
                handleKeyPress(event.key.code);
            }
        }
    }

    void InputManager::handleKeyPress(sf::Keyboard::Key key) {
        std::map<std::string, parameter> parameters;
        Message input_message("Player", parameters);
        misi::parameter param(0);
        if (key == sf::Keyboard::A)
        {

            input_message.set_id("Player");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("Move Left"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }

        if (key == sf::Keyboard::D)
        {
            input_message.set_id("Player");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("Move Right"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }

        if (key == sf::Keyboard::Space)
        {
            input_message.set_id("Player");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("Stop"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }

        if (key == sf::Keyboard::E)
        {
            input_message.set_id("Player");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("Special Move"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }

        if (key == sf::Keyboard::R)
        {
            input_message.set_id("Player");
            parameters.clear();
            parameters.insert(std::make_pair(std::string("Reset"), param));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }
          
    }

    void InputManager::handle(const Message& message)
    {
        std::string key;
        parameter value;
        for (const auto& entry : message.parameters) {
            key = entry.first;
            value = entry.second;
        }
        if (key == "example")
        {

        }
    }
};