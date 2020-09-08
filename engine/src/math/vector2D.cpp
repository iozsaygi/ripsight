#include "vector2D.h"

namespace engine
{
	Vector2D::Vector2D()
	{
		m_X = 0.0f;
		m_Y = 0.0f;
	}

	Vector2D::Vector2D(float x, float y)
	{
		m_X = x;
		m_Y = y;
	}

	Vector2D::Vector2D(const Vector2D& vector2D)
	{
		m_X = vector2D.m_X;
		m_Y = vector2D.m_Y;
	}

	Vector2D Vector2D::Zero()
	{
		return Vector2D(0.0f, 0.0f);
	}

	Vector2D Vector2D::One()
	{
		return Vector2D(1.0f, 1.0f);
	}

	float Vector2D::GetX()
	{
		return m_X;
	}

	float Vector2D::GetY()
	{
		return m_Y;
	}
}