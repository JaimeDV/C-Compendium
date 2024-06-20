/// @copyright © 2023+ Jaime díaz viéitez
/// @author Author: Jaime Díaz Viéitez
/// pamecin@gmail.com
/// @date 20/12/2023
/// @brief Implements the funtión defined in AudioManager.hpp
///
#include "../headers/AudioManager.hpp"
#include <SDL.h>
#include <string>

namespace misi
{
	bool AudioManager::sdl_audio_initialized = false;

	/// @brief AudioManager controller
	/// @param frequency of the sound, afects the tone of sounds, any value over 44100 is unhearable by the average human
	/// @param chanels from how many "locations" the sound is coming 1=mono 2=Stereo
	/// @param chunk_size size of the audio buffer
	AudioManager::AudioManager(int frequency = 44100, unsigned int chanels = 2, int chunk_size = 4096)
	{
		initialize_audio();
		auto result = Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, chanels, chunk_size);
		if (result < 1)
		{
			SDL_Log("No se ha podido inicializar el subsistema de audio.");
		}
	}

	/// @brief destructor for AudioManager, stops all audio and realeses the audio references
	AudioManager::~AudioManager()
	{
		Mix_HaltMusic();
		Mix_HaltChannel(-1);
		Mix_FreeMusic(music);
		Mix_FreeChunk(sound);
		music = nullptr;
		sound = nullptr;
	}

	/// @brief instantiates the SDL Audio
	void AudioManager::initialize_audio()
	{
		auto result = SDL_Init(SDL_INIT_AUDIO);
		if (result < 0)
		{
			SDL_Log("No se ha podido inicializar SDL2.");
		}
		sdl_audio_initialized = result == 0;

		SDL_assert(sdl_audio_initialized == true);

		atexit(finalize_sdl);
	}

	//void AudioManager::start_audio_loop()
	//{
	//	do
	//	{
	//		//aqui se reciven eventos de sonido
	//	} while (!exit);
	//}

	/// @brief AudioManager controller
	/// @param loops The amount of times it repeats if you want to loop "forever" set to -1
	/// @param fades if true the music starts muted annd progresibly gets louder until reaching maximun value
	/// @param fadeTime if it fades how long it takes the audio to reach maximun value
	void AudioManager::play_music(int loops, bool fades, int fadeTime = 0)
	{
		if (music != nullptr)
		{
			if (fades) {
				Mix_FadeInMusic(music, loops, fadeTime);
			}
			else
			{
				Mix_PlayMusic(music, loops);
			}
		}
	}

	/// @brief plays the audio held in the manager in a free channel.
	void AudioManager::play_sound()
	{
		if (sound) {
			Mix_PlayChannel(-1, sound, 0);
		}
	}
	/// @brief Changes the volume of the cuarrent sound clip
	/// @param volume The new volume of the clip, the maximun is 128
	void AudioManager::change_sound_volume(unsigned volume)
	{
		if (sound) {
			Mix_VolumeChunk(sound, volume);
		}
	}
	/// @brief Changes the volume of the cuarrent music clip
	/// @param volume The new volume of the music, the maximun is 128
	void AudioManager::change_music_volume(unsigned volume)
	{
		if (music) {
			Mix_VolumeMusic(volume);
		}
	}
	/// @brief Changes the music clip
	/// @param file path to the audio file, should be relative if possible
	void AudioManager::change_music_clip(const char* file) {
		if (not (music = Mix_LoadMUS(file)))
		{
			SDL_Log("No se ha podido cargar la musica");
		}
	}

	/// @brief Changes the sound clip
	/// @param file path to the sound file, should be relative if possible
	void AudioManager::change_sound_clip(const char* file) {
		if (not (sound = Mix_LoadWAV(file)))
		{
			SDL_Log("No se ha podido cargar la musica");
		}
	}

	void AudioManager::finalize_sdl()
	{
		SDL_Quit();
	}

	void AudioManager::handle(const Message& message)
	{
		std::string key_d;
		std::pair<parameter, parameter> value_d;
		std::string key;
		parameter value;
		for (const auto& entry : message.parameters) {
			key = entry.first;
			value = entry.second;
		}
		for (const auto& entry : message.double_parameters) {
			key_d = entry.first;
			value_d = entry.second;
		}
		if (key == "Change Sound Clip")
		{
			std::string s_file = std::get<std::string>(value);
			change_sound_clip(s_file.c_str());
		}
		if (key == "Play Sound")
		{
			play_sound();
		}
	}
}