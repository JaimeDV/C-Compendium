/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 19/11/2023
/// @brief Controls the function & classes of the game engine window

#include "../headers/Window.hpp"
#include "../headers/Macros.hpp"
#include <SDL.h>
#include <OpenGL.hpp>
#include <cassert>

namespace misi
{
	bool Window::sdl_video_initialized = false;

	/// @brief fullscreen window constructor
	/// @param title The text shown in the upperleft corner of the window
	/// @param width horizontal size of the window
	/// @param height vertical size of the window
	/// @param fullscreen check if the window is fullscreen or not
	Window::Window(const std::string& title, unsigned width, unsigned height, bool full_screen)
	{
		set_exit(false);
		w_handle = nullptr;
		gl_context = nullptr;

		if (initialize(SDL_INIT_VIDEO))
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			w_handle = SDL_CreateWindow
			(
				title.c_str(),
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
			);

			assert(w_handle != nullptr);

			if (w_handle)
			{
				gl_context = SDL_GL_CreateContext(w_handle);

				assert(gl_context != nullptr);

				if (gl_context && glt::initialize_opengl_extensions())
				{
					if (full_screen)
					{
						SDL_SetWindowFullscreen(w_handle, SDL_WINDOW_FULLSCREEN_DESKTOP);
					}
				}
			}
		}
	}
	bool Window::initialize(int subsystem)
	{
		// Se hace que al salir de la función main() se invoque automáticamente
		// a la función finalize() una vez:

		static bool finalize_is_not_set = true;

		if (finalize_is_not_set)
		{
			finalize_is_not_set = false;

			std::atexit(SDL_Quit);
		}

		// Se inicializa el subsistema si no estaba inicializado:

		if (!SDL_WasInit(subsystem))
		{
			return SDL_Init(subsystem) == 0;
		}

		return true;
	}

	/// @brief windowed window constructor
	/// @param title The text shown in the upperleft corner of the window
	/// @param x,y   2d representation of the space the window generates at
	/// @param width horizontal size of the window
	/// @param height vertical size of the window
	Window::Window(const std::string& title, unsigned x, unsigned y, unsigned width, unsigned height)
	{
		set_exit(false);
		w_handle = nullptr;
		gl_context = nullptr;

		if (initialize(SDL_INIT_VIDEO))
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
			w_handle = SDL_CreateWindow
			(
				title.c_str(),
				x,
				y,
				width,
				height,
				SDL_WINDOW_SHOWN
			);

			assert(w_handle != nullptr);

			if (w_handle)
			{
				gl_context = SDL_GL_CreateContext(w_handle);

				assert(gl_context != nullptr);

				if (gl_context && glt::initialize_opengl_extensions())
				{
					
				}
			}
		}
	}

	/// @brief calls the SDL_DestroyWindow funtion
	Window::~Window()
	{
		SDL_assert(w_handle != nullptr);
		if (gl_context) SDL_GL_DeleteContext(gl_context);
		if (w_handle) SDL_DestroyWindow(w_handle);
	}

	/// @brief returns the width of the given window
	/// @return width of the window
	unsigned Window::get_width() const
	{
		int width;

		SDL_GetWindowSize(w_handle, &width, nullptr);

		return unsigned(width);
	}

	/// @brief returns the height of the given window
	/// @return height of the window
	unsigned Window::get_height() const
	{
		int height;

		SDL_GetWindowSize(w_handle, nullptr, &height);

		return unsigned(height);
	}

	/// @brief returns whether or not the window is fullscreen
	/// @return true if fullscreen false if windowed
	bool Window::is_full_screen() const
	{
		Uint32 window_flags = SDL_GetWindowFlags(w_handle);

		return (window_flags & SDL_WINDOW_FULLSCREEN) != 0;
	}

	/// @brief Initializes the windows, creating the object in screen
	void Window::initialize_video()
	{
		if (not sdl_video_initialized)
		{
			auto result = SDL_Init(SDL_INIT_VIDEO);
			if (result < 0)
			{
				SDL_Log("No se ha podido inicializar SDL2.");
			}
			sdl_video_initialized = result == 0;

			SDL_assert(sdl_video_initialized == true);

			atexit(finalize_sdl);
		}
	}

	/// @brief Starts the Main window loop
	void Window::video_loop()
	{
		bool exit;
		exit = window_status(); //aqui llamar a un evento !!!!!!!!!!!!!!!!!!!!!!!!
	}

	//@brief checks if the status of the window, when quit returns true
	bool Window::window_status() {
		SDL_Event event;
		while (SDL_PollEvent(&event) > 0)
		{
			if (event.type == SDL_QUIT)
			{
				return true;
			}
		}
		return false;
	}

	void Window::finalize_sdl()
	{
		SDL_Quit();
	}

	void Window::clear() const
	{
		if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::swap_buffers() const
	{
		if (gl_context) SDL_GL_SwapWindow(w_handle);
	}

	void Window::handle(const Message& message)
	{
		std::string key;
		parameter value;
		for (const auto& entry : message.parameters) {
			key = entry.first;
			value = entry.second;
		}
		if (key == "Exit")
		{
			set_exit(true);
			finalize_sdl();
		}
	}
}