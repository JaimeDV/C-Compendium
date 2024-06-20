/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 14/12/2023
/// @brief contains definitions and classes for the main sound reproduction loop

#pragma once
#include <SDL_mixer.h>
#include <SDL_log.h>
#include<stdlib.h>
#include "Message.hpp"
namespace misi
{
	class AudioManager: public Message_Listener
	{
		static bool sdl_audio_initialized;

		Mix_Music* music;
		Mix_Chunk* sound; //this engine only suport one sound at a time
		
	public:
		AudioManager(int frequency, unsigned int chanels, int chunk_size);

		~AudioManager();

		void play_sound();
		void play_music(int loops, bool fades, int fadeTime);
		void change_music_volume(unsigned volume);
		void change_sound_volume(unsigned volume);
		void change_music_clip(const char* file);
		void change_sound_clip(const char* file);
		virtual void handle(const Message& message) override;
	private:
		/*void start_audio_loop();*/
		static void initialize_audio();
		static void finalize_sdl();
	};
}