/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 25/12/2023
/// @brief Implements the grafict funtion using some Sdl2Examples code
#include "../headers/Window.hpp"
#include "../headers/SampleRenderer.hpp"
namespace misi
{

    Sample_Renderer::Sample_Renderer(Window& given_window)
    {
        exit = false;
        window = &given_window;
        message_dispacher = nullptr;
        // Se crea el render node de OpenGL Toolkit:

        renderer.reset(new glt::Render_Node);


        // Se crean los elementos básicos necesarios para dibujar un cubo:

        shared_ptr< glt::Camera > camera(new  glt::Camera(40.f, 1.f, 50.f, 1.f)); //up , , , dunno
        shared_ptr<  glt::Light  > light(new  glt::Light());
        renderer->add("camera", camera);
        renderer->add("light", light);
       
        renderer->get("light")->translate(glt::Vector3(10.f, 10.f, 10.f));
        renderer->get("camera")->translate(glt::Vector3(0.f, 10.f, 0.f));
        renderer->get("camera")->rotate_around_x(-1.5);
    }
	void Sample_Renderer::render()
	{
        // Se ajusta el viewport por si el tamaño de la ventana ha cambiado:

        GLsizei width = GLsizei(window->get_width());
        GLsizei height = GLsizei(window->get_height());

        renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

        glViewport(0, 0, width, height);


       /* auto cube = renderer->get("cube");

        cube->rotate_around_x(0.01f);
        cube->rotate_around_y(0.02f);
        cube->rotate_around_z(0.03f);*/

        // Se renderiza la escena y se intercambian los buffers de la ventana para
        // hacer visible lo que se ha renderizado:

        window->clear();

        renderer->render();

        window->swap_buffers();
	}

    Sample_Renderer::~Sample_Renderer()
    {
        // En este caso es necesario definir explícitamente el destructor en el archivo
        // de implementación (CPP) para que el compilador pueda destruir el Render_Node
        // pese a que no hay código explícito.
    }

    //@brief starts the render loop and keeps doing it until an exit condition
    void Sample_Renderer::renderloop()
    {
            render();
    }

    //@brief adds a cube to the scene at default position.
    void Sample_Renderer::add_cube(string id)
    {
        //does not implement yet an automatic id, 
        shared_ptr<  glt::Model  > cube(new  glt::Model);
        cube->add(shared_ptr< glt::Drawable >(new glt::Cube), glt::Material::default_material());
        models.insert(std::make_pair(id, cube));
        renderer->add(id, cube);
    }
    //@brief adds a model from files to the scene at default position.
    void Sample_Renderer::add_model(string id, string given_model)
    {
        shared_ptr<  glt::Model  > model(new  glt::Model_Obj(given_model));
        id = "cube";
        models.insert(std::make_pair(id, model));
        renderer->add(id, model);
    }

    //@brief sets the position of a model to the one defined in position.
    void Sample_Renderer::move_model(string id, glt::Vector3 position)
    {
        renderer->get(id)->translate(position);
    }

    //@brief scales all the axis of a model based on the scale vector.
    void Sample_Renderer::scale_model(string id, glt::Vector3 scale)
    {
        renderer->get(id)->scale(scale.x, scale.y, scale.z);
    }

    //@brief scales all the axis of a model based to the same float value
    void Sample_Renderer::scale_model(string id, float scale)
    {
        renderer->get(id)->scale(scale);
    }

    //@brief rotates a model based on a vector 3 of rotation
    void Sample_Renderer::rotate_model(string id, glt::Vector3 rotation)
    {
        renderer->get(id)->rotate_around_x(rotation.x);
        renderer->get(id)->rotate_around_y(rotation.y);
        renderer->get(id)->rotate_around_z(rotation.z);
    }

    //@brief due to time constrains only makes the model invisible
    void Sample_Renderer::remove_model(string id)
    {
        models.erase(id);
        renderer->get(id)->is_not_visible();
    }

    //@brief adds a camera at a given position. Since the engine creates one by default should not be used unless there is a good reason
    void Sample_Renderer::add_camera(string id, glt::Vector3 position)
    {
        shared_ptr<  glt::Camera > camera(new  glt::Camera(position.x, position.y, position.z, 1.f));
        renderer->add(id, camera);
    }

    //@brief adds a light to the given position
    void Sample_Renderer::add_light(string id, glt::Vector3 position)
    {
        shared_ptr<  glt::Light  > light(new  glt::Light);

        renderer->add(id, light);
        renderer->get(id)->translate(position);
    }

    //@brief sets the parent of the object
    void Sample_Renderer::add_parent(string son, string parent)
    {
        renderer->get(son)->set_parent(renderer->get(parent));
    }
    //@brief sets the son of the object, does the same as add parent but reversed
    void Sample_Renderer::add_son(string parent, string son)
    {
        add_parent(son, parent);
    }

    //@brief Sets the visibility of the given model
    //@param id the name of the model to change
    //@param visibility the value of visibility-> true=visible ,false=invisible
    void Sample_Renderer::set_visibility(string id, bool visibility)
    {
        renderer->get(id)->set_visible(visibility);
    }

    //some funtions are umplimented at the moment
    void Sample_Renderer::handle(const Message& message)
    {
        std::string key;
        parameter value;
        std::string key_d;
        std::pair<parameter, parameter> value_d;
        std::map<std::string, parameter> parameters;
        Message input_message("PlayerManager", parameters);
        for (const auto& entry : message.parameters) {
            key = entry.first;
            value = entry.second;
        }
        for (const auto& entry : message.double_parameters) {
            key_d = entry.first;
            value_d = entry.second;
        }
        if (key == "Add Cube")
        {
            std::string s_value = std::get<std::string>(value);
            add_cube((string)s_value);
        }
        if (key == "Get Position") //not generalized at the moment
        {
            std::string s_value = std::get<std::string>(value);
            auto& position =renderer->get(s_value)->get_transformation();
            input_message.set_id("PlayerManager");
            parameters.clear();
            glm::vec3 glmVector = glm::vec3(position[3]);
            std::vector<float> stdVector{ glmVector.x, glmVector.y, glmVector.z };
            parameters.insert(std::make_pair("Return Position", stdVector));
            input_message.set_params(parameters);
            message_dispacher->send(input_message);
        }
        if (key_d == "Move Model")
        {
            std::string s_id = std::get<std::string>(value_d.first);
            std::vector<float>position =std::get<std::vector<float>>(value_d.second);
            glt::Vector3 v_position= glm::vec3((float)position[0], (float)position[1], (float)position[2]);
            move_model(s_id, v_position);
        }
        if (key_d == "Add Parent")
        {
            std::string s_son = std::get<std::string>(value_d.first);
            std::string s_parent = std::get<std::string>(value_d.second);
            add_parent(s_son, s_parent);
        }
        if (key_d == "Set visible")
        {
            std::string s_object = std::get<std::string>(value_d.first);
            std::string s_visibility = std::get<std::string>(value_d.second);
            if (s_visibility == "True")
            {
                set_visibility(s_object, true);
            }
            else
            {
                set_visibility(s_object, false);
            }
         
        }
        if (key_d == "Scale")
        {
            std::string s_id = std::get<std::string>(value_d.first);
            std::vector<float>scale = std::get<std::vector<float>>(value_d.second);
            glt::Vector3 v_scale = glm::vec3((float)scale[0], (float)scale[1], (float)scale[2]);
            scale_model(s_id, v_scale);
        }
        if (key_d == "Rotate")
        {
            std::string s_id = std::get<std::string>(value_d.first);
            std::vector<float>rotation = std::get<std::vector<float>>(value_d.second);
            glt::Vector3 v_rotation = glm::vec3((float)rotation[0], (float)rotation[1], (float)rotation[2]);
            rotate_model(s_id, v_rotation);
        }

    }

}