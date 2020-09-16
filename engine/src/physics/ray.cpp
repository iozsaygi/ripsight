#include "ray.h"

namespace engine
{
	Ray::Ray()
	{
		m_Origin = Vector2D::Zero();
		m_Direction = Vector2D::One();
		m_Length = 1.0f;
	}

	Ray::Ray(Vector2D origin, Vector2D direction, float length)
	{
		m_Origin = origin;
		m_Direction = direction;
		m_Length = length;
	}

	Vector2D Ray::GetOrigin()
	{
		return m_Origin;
	}

	Vector2D Ray::GetDirection()
	{
		return m_Direction;
	}

	float Ray::GetLength()
	{
		return m_Length;
	}
}