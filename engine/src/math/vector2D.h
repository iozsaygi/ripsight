#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace engine
{
	struct Vector2D
	{
	public:
		Vector2D();
		Vector2D(float x, float y);
		Vector2D(const Vector2D& vector2D);

		static Vector2D Zero();
		static Vector2D One();

		float GetX();
		float GetY();

	private:
		float m_X;
		float m_Y;
	};
}

#endif // !VECTOR2D_H