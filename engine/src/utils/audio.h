#ifndef AUDIO_H
#define AUDIO_H

#include <string>
#include <SDL_mixer.h>

namespace engine
{
	Mix_Chunk* LoadWaveChunk(const std::string& path);
}

#endif // !AUDIO_H