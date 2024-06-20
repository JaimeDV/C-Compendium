/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 27/12/2023
/// @brief implements scene classes that holds the kernel loop

#include "..\headers\Scene.hpp"
#include "..\headers\Task.hpp"
#include "..\headers\Kernel.hpp"
#include "..\headers\InputManager.hpp"
#include "..\headers\SampleRenderer.hpp"
#include "..\headers\AudioManager.hpp"
namespace misi
{
	Scene::Scene(string given_name, unsigned width, unsigned height, bool full_screen) : kernel(new Kernel())
	{
		/*
			1 leer imput
			2 actualizar logica
			3 renderizar
			4 swapbuffersg
			5 Sleep
			*/
		scene_name = given_name;
		
		Input_Task* inputTask = new Input_Task(this);
		Update_Task* updateTask = new Update_Task(this, scene_name, width, height, full_screen);
		Render_Task* renderTask = new Render_Task(this, updateTask);
		Audio_Task* audioTask = new Audio_Task(this);
		Sync_task* syncTask = new Sync_task(this);
		Message_Dispacher* mesageTask = new Message_Dispacher(this);

		player = new player_controller(mesageTask);
		mesageTask->add(*player, "PlayerManager");

		mesageTask->add(*this->get_message_Listener(), "SceneManager");
		mesageTask->add(*inputTask->get_input(), "InputManager");
		mesageTask->add(*updateTask->get_window(), "WindowManager");
		mesageTask->add(*renderTask->get_renderer(), "RenderManager");
		mesageTask->add(*audioTask->get_audio(), "AudioManager");

		renderTask->get_renderer()->set_message_dispacher(mesageTask);
		updateTask->get_window()->set_message_dispacher(mesageTask);
		inputTask->get_input()->set_message_dispacher(mesageTask);

		kernel->add(reinterpret_cast<Task**>(&syncTask));
		kernel->add(reinterpret_cast<Task**>(&audioTask));
		kernel->add(reinterpret_cast<Task**>(&renderTask));
		kernel->add(reinterpret_cast<Task**>(&mesageTask));
		kernel->add(reinterpret_cast<Task**>(&updateTask));
		kernel->add(reinterpret_cast<Task**>(&inputTask));

		kernel->set_dispacher(mesageTask);

		std::map<std::string, parameter> parameters;
		Message scene_message("PlayerManager", parameters);
		scene_message.set_id("PlayerManager");
		parameters.insert(std::make_pair("Start", 0));
		scene_message.set_params(parameters);
		mesageTask->send(scene_message);

	}
	Scene::Scene(string given_name, unsigned x, unsigned y, unsigned width, unsigned height) : kernel(new Kernel())
	{
		/*
			1 leer imput
			2 actualizar logica
			3 renderizar
			4 swapbuffersg
			5 Sleep
			*/
		scene_name = given_name;
		Input_Task* inputTask = new Input_Task(this);
		Update_Task* updateTask = new Update_Task(this, scene_name, x, y, width, height);
		Render_Task* renderTask = new Render_Task(this, updateTask);
		Audio_Task* audioTask = new Audio_Task(this);
		Sync_task* syncTask = new Sync_task(this);
		Message_Dispacher* mesageTask = new Message_Dispacher(this);

		player = new player_controller(mesageTask);
		mesageTask->add(*player, "PlayerManager");

		mesageTask->add(*this->get_message_Listener(), "SceneManager");
		mesageTask->add(*inputTask->get_input(), "InputManager");
		mesageTask->add(*updateTask->get_window(), "WindowManager");
		mesageTask->add(*renderTask->get_renderer(), "RenderManager");
		mesageTask->add(*audioTask->get_audio(), "AudioManager");

		renderTask->get_renderer()->set_message_dispacher(mesageTask);
		updateTask->get_window()->set_message_dispacher(mesageTask);
		inputTask->get_input()->set_message_dispacher(mesageTask);

		kernel->add(reinterpret_cast<Task**>(&syncTask));
		kernel->add(reinterpret_cast<Task**>(&audioTask));
		kernel->add(reinterpret_cast<Task**>(&renderTask));
		kernel->add(reinterpret_cast<Task**>(&mesageTask));
		kernel->add(reinterpret_cast<Task**>(&updateTask));
		kernel->add(reinterpret_cast<Task**>(&inputTask));

		kernel->set_dispacher(mesageTask);

		std::map<std::string, parameter> parameters;
		Message scene_message("PlayerManager", parameters);
		scene_message.set_id("PlayerManager");
		parameters.insert(std::make_pair("Start", 0));
		scene_message.set_params(parameters);
		mesageTask->send(scene_message);

	}
	void Scene::run()
	{
		kernel->run();
		/*aqui va el kernel loop
			ahora bien podria tan bien hacerse no en una escena*/
	}
	void Message_Listener::handle(const Message& message)
	{
		std::string key;
		parameter value;
		for (const auto& entry : message.parameters) {
			key = entry.first;
			value = entry.second;
		}
		

	}
}