#ifndef IMG_H
#define IMG_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>

namespace engine
{
	SDL_Texture* LoadImage(SDL_Renderer* renderer, const std::string& path);
}

#endif // !IMG_H