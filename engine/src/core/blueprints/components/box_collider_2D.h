#ifndef BOX_COLLIDER_2D_H
#define BOX_COLLIDER_2D_H

#include <SDL.h>
#include "core/common/actor.h"
#include "core/blueprints/components/transform.h"
#include "core/common/component.h"
#include "math/vector2D.h"

namespace engine
{
	class BoxCollider2D : public Component
	{
	public:
		BoxCollider2D(Actor* owner) : Component(owner)
		{
			m_ColliderRectangle.w = m_OwnerTransform->GetScale().GetX();
			m_ColliderRectangle.h = m_OwnerTransform->GetScale().GetY();
		}

		BoxCollider2D(Actor* owner, Vector2D size) : Component(owner)
		{
			m_ColliderRectangle.w = size.GetX();
			m_ColliderRectangle.h = size.GetY();
		}

		void Birth() override;
		void OnTick(float deltaTime) override;

		// Do not call this from client code.
		SDL_Rect GetColliderRectangle();

	private:
		Transform* m_OwnerTransform = nullptr;
		SDL_Rect m_ColliderRectangle;
	};
}

#endif // !BOX_COLLIDER_2D_H