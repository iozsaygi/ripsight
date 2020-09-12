#include <assert.h>
#include "box_collider_2D.h"

namespace engine
{
	void BoxCollider2D::Birth()
	{
		assert(GetOwner() != nullptr);
		m_OwnerTransform = GetOwner()->GetComponent<Transform>();
	}

	void BoxCollider2D::OnTick(float deltaTime)
	{
		m_ColliderRectangle.x = m_OwnerTransform->GetPosition().GetX();
		m_ColliderRectangle.y = m_OwnerTransform->GetPosition().GetY();
	}

	SDL_Rect BoxCollider2D::GetColliderRectangle()
	{
		return m_ColliderRectangle;
	}
}