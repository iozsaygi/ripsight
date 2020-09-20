#include <SDL.h>
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

	bool Transform::IsPositionInsideMe(Vector2D& position)
	{
		// Convert given position for SDL.
		SDL_Point givenPoint;
		givenPoint.x = position.GetX();
		givenPoint.y = position.GetY();

		// Convert my position and scale to SDL_Rect.
		SDL_Rect myPosition;
		myPosition.x = this->GetPosition().GetX();
		myPosition.y = this->GetPosition().GetY();
		myPosition.w = this->GetScale().GetX();
		myPosition.h = this->GetScale().GetY();

		// Check and return if converted point is inside crafted position.
		return SDL_PointInRect(&givenPoint, &myPosition);
	}
}