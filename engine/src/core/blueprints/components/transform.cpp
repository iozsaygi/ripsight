#include "transform.h"

namespace engine
{
	Vector2D& Transform::GetPosition()
	{
		return m_Position;
	}

	Vector2D& Transform::GetScale()
	{
		return m_Scale;
	}
}