#include <assert.h>
#include "utils/img.h"
#include "sprite_renderer.h"

namespace engine
{
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

	void SpriteRenderer::UpdateRenderAngle(double renderAngle)
	{
		m_RenderAngle = renderAngle;
	}

	void SpriteRenderer::Render(SDL_Renderer* renderer)
	{
		if (m_OwnerTransform != nullptr)
		{
			SDL_Rect renderRectangle;
			renderRectangle.x = m_OwnerTransform->GetPosition().GetX();
			renderRectangle.y = m_OwnerTransform->GetPosition().GetY();
			renderRectangle.w = m_OwnerTransform->GetScale().GetX();
			renderRectangle.h = m_OwnerTransform->GetScale().GetY();

			SDL_RenderCopyEx(renderer, m_InitialSprite, nullptr, &renderRectangle, m_RenderAngle, nullptr, SDL_FLIP_NONE);
		}
	}
}