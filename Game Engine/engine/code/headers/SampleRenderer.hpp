/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 14/12/2023
/// @brief contains definitions and classes for the main grafical render loop

#pragma once

#include <memory>
#include <string>
#include "Internal.hpp"
#include <Cube.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <Light.hpp>
#include <Render_Node.hpp>
using namespace std;
namespace misi
{

    class Window;
    class Sample_Renderer: public Message_Listener
    {

        Message_Dispacher* message_dispacher;
        std::unique_ptr< glt::Render_Node > renderer;

        std::map<string, shared_ptr< glt::Model> > models;//a list of all renderer models with their ids

        Window* window;

        bool exit;

        
    public:

        Sample_Renderer(Window& given_window);

        ~Sample_Renderer();

        void render();

        void add_model(string id, string file);

        void move_model(string id, glt::Vector3 position);

        void scale_model(string id, glt::Vector3 scale);

        void scale_model(string id, float scale);

        void rotate_model(string id, glt::Vector3 rotation);

        void remove_model(string id);

        void add_cube(string id);

        void add_camera(string id,glt::Vector3 position);

        void add_light(string id, glt::Vector3 position);

        void add_parent(string son, string parent);
        
        void add_son(string parent, string son);

        void renderloop();

        void set_visibility(string id, bool value);

        virtual void handle(const Message& message) override;
        
        Message_Dispacher* get_message_dispacher()
        {
            return message_dispacher;
        }
        void set_message_dispacher(Message_Dispacher* given_dispacher)
        {
            message_dispacher = given_dispacher;
        }
    };
}