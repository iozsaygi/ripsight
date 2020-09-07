#include <assert.h>
#include "utils/img.h"
#include "sprite_renderer.h"

namespace engine
{
	SpriteRenderer::SpriteRenderer(const std::string& spritePath)
	{
		m_Path = spritePath;
	}

	SpriteRenderer::~SpriteRenderer()
	{
		SDL_DestroyTexture(m_InitialSprite);
	}

	void SpriteRenderer::UpdateRenderer(SDL_Renderer* renderer)
	{
		assert(renderer != nullptr);
		m_Renderer = renderer;
		m_InitialSprite = LoadImage(m_Renderer, m_Path);
	}

	void SpriteRenderer::Render(SDL_Renderer* renderer)
	{
		// This is temporary calculation.
		SDL_Rect renderRectangle;
		renderRectangle.x = 200;
		renderRectangle.y = 250;
		renderRectangle.w = 64;
		renderRectangle.h = 64;

		SDL_RenderCopy(renderer, m_InitialSprite, nullptr, &renderRectangle);
	}
}