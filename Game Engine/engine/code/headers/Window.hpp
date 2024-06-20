/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief contains definitions and classes for windows class

#pragma once
#include <string>
#include "Message.hpp"
struct  SDL_Window; //permite acced a sdl sin dependencia a la libreria
typedef void* SDL_GLContext;
namespace misi
{
	class Window: public Message_Listener
	{
		static bool sdl_video_initialized;
		Message_Dispacher* message_dispacher;
		SDL_Window* w_handle;
		SDL_GLContext gl_context;
		bool exit;
	public:

		Window(const std::string& title, unsigned width, unsigned height, bool full_screen = true);
		Window(const std::string& title, unsigned x, unsigned y, unsigned width, unsigned height);

		~Window();

		unsigned get_width() const;
		unsigned get_height() const;
		bool is_full_screen() const;
		bool window_status();
		void clear() const;
		void swap_buffers() const;
		void video_loop();
		void initialize_video();
		bool initialize(int subsystem);
		virtual void handle(const Message& message) override;

		Message_Dispacher* get_message_dispacher()
		{
			return message_dispacher;
		}
		void set_message_dispacher(Message_Dispacher* given_dispacher)
		{
			message_dispacher = given_dispacher;
		}
		void set_exit(bool value)
		{
			exit = value;
		}
		bool get_exit() const
		{
			return exit;
		}
	private:
		static void finalize_sdl();
	};
}