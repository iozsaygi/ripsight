#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

#include <string>
#include <SDL_mixer.h>
#include "core/common/component.h"

namespace engine
{
	class AudioPlayer : public Component
	{
	public:
		AudioPlayer(Actor* owner, const std::string& path) : Component(owner)
		{
			m_Path = path;
		}

		~AudioPlayer();

		void Birth() override;
		void PlayOneShot(int channelID, int volume);

	private:
		std::string m_Path;
		Mix_Chunk* m_WaveChunk = nullptr;
	};
}

#endif // !AUDIO_PLAYER_H