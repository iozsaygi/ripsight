#ifndef RAY_H
#define RAY_H

#include "math/vector2D.h"

namespace engine
{
	struct Ray
	{
	public:
		Ray();
		Ray(Vector2D origin, Vector2D direction, float length);

		Vector2D GetOrigin();
		Vector2D GetDirection();
		float GetLength();
		
	private:
		Vector2D m_Origin;
		Vector2D m_Direction;
		float m_Length;
	};
}

#endif // !RAY_H