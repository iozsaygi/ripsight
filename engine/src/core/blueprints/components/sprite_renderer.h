#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "core/common/component.h"

namespace engine
{
	// Responsible for rendering target sprites to the screen.
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer(const std::string& spritePath);
		~SpriteRenderer();

		void UpdateRenderer(SDL_Renderer* renderer);
		void Render(SDL_Renderer* renderer);

	private:
		std::string m_Path;
		SDL_Renderer* m_Renderer = nullptr;
		SDL_Texture* m_InitialSprite = nullptr;
	};
}

#endif // !SPRITE_RENDERER_H