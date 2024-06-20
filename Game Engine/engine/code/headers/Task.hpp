/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/12/2023
/// @brief Defines task classes that the kernel call in every loop

#pragma once
#include <string> //pa mensaje
#include <variant> //pa mesaje
#include <list> //pa mesaje
#include <map> //pa mesaje


namespace misi
{
	class InputManager;
	class AudioManager;
	class Sample_Renderer;
	class Window;
	class Scene;
	class Message_Dispacher;
	class Task
	{
		unsigned int priority; //between 1-10 les value equals more priority
		bool consumible; //if true when done the kernel removes it after
		Scene* owner;
	public:
		std::string task_name;
		Task()
		{
			owner = nullptr;
			priority = 0;
			consumible = false;

		}
		Task(Scene* given_owner): owner(given_owner)
		{
			priority = 0;
			consumible = false;
		}
		Task(int given_priority, Scene* given_owner) :priority(given_priority),owner(given_owner) {
			consumible = false;
		}
		Task(int given_priority, bool given_consumible, Scene* given_owner) :priority(given_priority), consumible(given_consumible), owner(given_owner) {}
		virtual bool execute(float t) = 0; //t is time
		//virtual void initialize() {};//optional /Unimplemeted, could not find a good use at the moment
		//virtual void finalize() {};//optional
		virtual bool get_consumable()
		{
			return consumible;
		}

		virtual void set_consumable(bool given_Consumible)
		{
			 consumible= given_Consumible;
		}
		virtual void set_owner(Scene* given_owner)
		{
			owner = given_owner;
		}
		bool operator < (const Task& other) const
		{
			return this->priority < other.priority;
		};
	};

	class Input_Task : public Task {//1
		InputManager* inputManager;
		Message_Dispacher* message_dispacher;
	public:
		Input_Task(Scene* given_owner);
		bool execute(float t) override;
		InputManager* get_input()
		{
			return inputManager;
		}
		Message_Dispacher* get_message_dispacher()
		{
			return message_dispacher;
		}
		void set_message_dispacher(Message_Dispacher* given_dispacher)
		{
			message_dispacher = given_dispacher;
		}
		~Input_Task();
	};

	class Update_Task :public Task {//5

		Window * window;
		Message_Dispacher* message_dispacher;
	public:
		Update_Task(Scene* given_owner,  std::string title, unsigned width, unsigned height, bool full_screen = true);
		Update_Task(Scene* given_owner,  std::string title, unsigned x, unsigned y, unsigned width, unsigned height);
		bool execute(float t) override;
		Window* get_window()
		{
			return window;
		}
		Message_Dispacher* get_message_dispacher()
		{
			return message_dispacher;
		}
		void set_message_dispacher(Message_Dispacher* given_dispacher)
		{
			message_dispacher = given_dispacher;
		}
		~Update_Task();
	};


	class Render_Task :public Task {//9
	
		Sample_Renderer * renderer;
		Message_Dispacher* message_dispacher;
	public:
		Render_Task(Scene* given_owner, Update_Task* updateTask);
		bool execute(float t) override;
		Sample_Renderer* get_renderer()
		{
			return renderer;
		}
		Message_Dispacher* get_message_dispacher()
		{
			return message_dispacher;
		}
		void set_message_dispacher(Message_Dispacher* given_dispacher)
		{
			message_dispacher = given_dispacher;
		}
		~Render_Task();
	};

	class Sync_task :public Task {//10
		
	public:
		Sync_task(Scene* given_owner);
		bool execute(float t) override;
		~Sync_task();
	};

	class Audio_Task :public Task {//10
		AudioManager * audiomanager;
		
	public:
		Audio_Task(Scene* given_owner);
		bool execute(float t) override;
		AudioManager* get_audio()
		{
			return audiomanager;
		}
		~Audio_Task();
	};
}