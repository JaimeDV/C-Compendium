//here we implement input manager functon to avoid using
/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 14/12/2023
/// @brief contains implementations of the classes in inputManager.Hpp
#include "../headers/InputManager.hpp"
#include "../headers/KeyBoard.hpp"
#include "../headers/Mouse.hpp"
#include "../headers/Message.hpp"
#include <assert.h>
#include <string>
namespace misi
{
	//the game calls the input press event and update check the pile to see if it was pressed
	void InputManager::Update()
	{
			// Se procesan los eventos acumulados:

			SDL_Event event;
            std::map<std::string, parameter> parameters;
            Message input_message("PlayerManager", parameters); //solo escucha a los que tenga su nombre
            while (SDL_PollEvent(&event) > 0)
            {
                switch (event.type)
                {
                case SDL_KEYDOWN:
                {
                   
                    switch (event.key.keysym.sym)
                    {
                    case KeyA:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("A", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyB:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("B", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyC:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("C", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyD:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("D", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyE:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("E", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyG:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("G", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyH:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("H", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyI:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("I", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyJ:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("J", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyK:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("K", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyL:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("L", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyM:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("M", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyN:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("N", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyO:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("O", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyP:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("P", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyQ:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Q", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyR:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("R", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyS:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("S", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyT:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("T", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyU:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("U", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyV:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("V", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyW:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("W", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyX:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("X", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyY:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Y", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyZ:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Z", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key0:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("0", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key1:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("1", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key2:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("2", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key3:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("3", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key4:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("4", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key5:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("5", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key6:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("6", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key7:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("7", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key8:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("8", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case Key9:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("9", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyEscape:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Escape", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeySpace:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Space", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyEnter:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Enter", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyTab:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Tab", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyShift:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Shift", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyCtrl:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Ctrl", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyAlt:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("Alt", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF1:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F1", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF2:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F2", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF3:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F3", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF4:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F4", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF5:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F5", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF6:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F6", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF7:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F7", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF8:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F8", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF9:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F9", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF10:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F10", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF11:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F11", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;

                    case KeyF12:
                        input_message.set_id("PlayerManager");
                        parameters.clear();
                        parameters.insert(std::make_pair("F12", 0));
                        input_message.set_params(parameters);
                        message_dispacher->send(input_message);
                        break;
                    default:
                        // Handle other keys if needed
                        break;
                    }
                    break;
                }

                case SDL_MOUSEBUTTONDOWN:
                {
                    parameters.clear();
                    parameters.insert(std::make_pair("Click", 0));
                    input_message.set_params(parameters);
                    message_dispacher->send(input_message);
                    break;
                }
                case SDL_MOUSEMOTION:
                {
                    // Handle mouse events if needed
                    break;
                }

                case SDL_QUIT:
                {
                    exit = true;
                    input_message.set_id("WindowManager");
                    parameters.clear();
                    parameters.insert(std::make_pair("Exit", 1));
                    input_message.set_params(parameters);
                    message_dispacher->send(input_message);
                    break;
                }
                }
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
}