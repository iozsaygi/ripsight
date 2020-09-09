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

		Vector2D& Add(const Vector2D& other);
		Vector2D& Subtract(const Vector2D& other);
		Vector2D& Multiply(const Vector2D& other);
		Vector2D& Divide(const Vector2D& other);

		friend Vector2D& operator+(Vector2D& source, const Vector2D& other);
		friend Vector2D& operator-(Vector2D& source, const Vector2D& other);
		friend Vector2D& operator*(Vector2D& source, const Vector2D& other);
		friend Vector2D& operator/(Vector2D& source, const Vector2D& other);

		Vector2D& operator+=(const Vector2D& other);
		Vector2D& operator-=(const Vector2D& other);
		Vector2D& operator*=(const Vector2D& other);
		Vector2D& operator/=(const Vector2D& other);

	private:
		float m_X;
		float m_Y;
	};
}

#endif // !VECTOR2D_H