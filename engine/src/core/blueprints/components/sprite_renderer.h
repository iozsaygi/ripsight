#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "core/common/actor.h"
#include "core/common/component.h"
#include "core/blueprints/components/transform.h"
#include "public/engine_entry.h"

namespace engine
{
	// Responsible for rendering target sprites to the screen.
	class SpriteRenderer : public Component
	{
	public:
		inline SpriteRenderer(Actor* owner, EngineEntry* engineEntry, const std::string& spritePath) : Component(owner) 
		{
			m_Path = spritePath; 
			m_OwnerTransform = GetOwner()->GetComponent<Transform>();
			m_EngineEntry = engineEntry;
		}

		~SpriteRenderer();

		void Birth() override;

		void Render(SDL_Renderer* renderer);
		void UpdateRenderAngle(double renderAngle);

	private:
		std::string m_Path;
		SDL_Renderer* m_Renderer = nullptr;
		SDL_Texture* m_InitialSprite = nullptr;
		Transform* m_OwnerTransform = nullptr;
		double m_RenderAngle = 0.0;
		EngineEntry* m_EngineEntry = nullptr;
	};
}

#endif // !SPRITE_RENDERER_H