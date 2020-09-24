#include "img.h"

namespace engine
{
	SDL_Texture* LoadImage(SDL_Renderer* renderer, const std::string& path)
	{
		// TODO: Null check.
		SDL_Surface* surface = IMG_Load(path.c_str());

		if (surface == nullptr)
			SDL_Log("Failed to create surface from given image at path %s", path.c_str());

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		if (texture == nullptr)
			SDL_Log("Failed to load image at %s (Returning nullptr)", path.c_str());

		return texture;
	}
}