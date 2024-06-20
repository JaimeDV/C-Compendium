/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/12/2023
/// @brief Defines implementation of the classes defined in task.

#include "../headers/Task.hpp"
#include "../headers/Scene.hpp"
#include "../headers/SampleRenderer.hpp"
#include "../headers/InputManager.hpp"
#include "../headers/AudioManager.hpp"
namespace misi
{

	
	//Calls the execute function ot the input task
	bool Input_Task::execute(float time)
	{
		inputManager->Update();
		return false;
	}
	Input_Task::Input_Task(Scene* given_owner) : Task()
	{
		set_consumable(false);
		set_owner(given_owner);
		inputManager=new InputManager();
	}
	Input_Task::~Input_Task()
	{

	}


	//Calls the execute function ot the update task
	bool Update_Task::execute(float time)
	{
		window->video_loop();
		if (window->get_exit()==true)
		{
			return true;
		}
		return false;
	}

	Update_Task::Update_Task(Scene* given_owner,  std::string title, unsigned width, unsigned height,
		bool full_screen)
	{
		set_consumable(false);
		task_name = "UpdateTask";
		set_owner(given_owner);
		window = new Window(title,width,height,full_screen);
	}
	Update_Task::Update_Task(Scene* given_owner,  std::string title, unsigned x, unsigned y, unsigned width,
		unsigned height)
	{
		set_consumable(false);
		task_name = "UpdateTask";
		set_owner(given_owner);
		window = new Window(title, x, y, width,height);
	}

	Update_Task::~Update_Task()
	{

	}

	//Calls the execute function ot the render task
	bool Render_Task::execute(float time)
	{
		renderer->renderloop();
		return false;
	}

	Render_Task::Render_Task(Scene* given_owner, Update_Task* update):Task()
	{
		set_consumable(false);
		task_name = "RenderTask";
		set_owner(given_owner);
		Window* window = update->get_window();
		renderer = new Sample_Renderer(*window);
	}
	Render_Task::~Render_Task()
	{

	}

	//Calls the execute function ot the sync task
	bool Sync_task::execute(float time)
	{
		return false;
	}
	Sync_task::Sync_task(Scene* given_owner) :Task()
	{
		set_consumable(false);
		task_name = "SyncTask";
		set_owner(given_owner);
	}

	Sync_task::~Sync_task()
	{

	}
	//Calls the execute function ot the Audio task //unused, sounds are handled by events
	bool Audio_Task::execute(float time) 
	{
		/*audiomanager->change_sound_clip("../../../juego/asset/throw-knife.wav");
		audiomanager->play_sound();*/
		return false;
	}
	Audio_Task::Audio_Task(Scene* given_owner) :Task()
	{
		set_consumable(false);
		task_name = "AudioTask";
		set_owner(given_owner);
		audiomanager = new AudioManager(44100, 2, 4096);
	}
	Audio_Task::~Audio_Task()
	{

	}

}