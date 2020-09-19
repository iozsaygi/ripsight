#include "img.h"

namespace engine
{
	SDL_Texture* LoadImage(SDL_Renderer* renderer, const std::string& path)
	{
		// TODO: Null check.
		SDL_Surface* surface = IMG_Load(path.c_str());
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		return texture;
	}
}