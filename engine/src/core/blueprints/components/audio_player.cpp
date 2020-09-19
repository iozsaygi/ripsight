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

	void AudioPlayer::PlayOneShot(int channelID, int volume)
	{
		if (m_WaveChunk != nullptr)
		{
			Mix_Volume(channelID, volume);
			Mix_PlayChannel(channelID, m_WaveChunk, 0);
		}
	}
}