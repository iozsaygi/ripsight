#include "utils/audio.h"
#include "audio_player.h"

namespace engine
{
	AudioPlayer::~AudioPlayer()
	{
		Mix_FreeChunk(m_WaveChunk);
	}

	void AudioPlayer::Birth()
	{
		// Load the .wav file.
		m_WaveChunk = LoadWaveChunk(m_Path);
	}

	void AudioPlayer::PlayOneShot(int volume)
	{
		if (m_WaveChunk != nullptr)
		{
			Mix_Volume(-1, volume);
			Mix_PlayChannel(-1, m_WaveChunk, 0);
		}
	}
}