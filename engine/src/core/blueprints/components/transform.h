#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "core/common/component.h"
#include "math/vector2D.h"

namespace engine
{
	class Transform : public Component
	{
	public:
		inline Transform(Actor* owner) : Component(owner)
		{
			m_Position = Vector2D::Zero();
			m_Scale = Vector2D::One();
		}

		inline Transform(Actor* owner, const Vector2D& position, const Vector2D& scale) : Component(owner)
		{
			m_Position = position;
			m_Scale = scale;
		}

		Vector2D& GetPosition();
		Vector2D& GetScale();
		bool IsPositionInsideMe(Vector2D& position);

	private:
		Vector2D m_Position;
		Vector2D m_Scale;
	};
}

#endif // !TRANSFORM_H