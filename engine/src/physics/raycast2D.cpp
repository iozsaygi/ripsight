#include <SDL.h>
#include "math/vector2D.h"
#include "raycast2D.h"

namespace engine
{
	Actor* Raycast2D(Ray ray)
	{
		// Get the current active world.
		auto world = WorldManager::GetActiveWorld();
		if (world != nullptr)
		{
			auto normalizedOrigin = ray.GetOrigin().GetNormalized();
			for (int i = 0; i < ray.GetLength(); i++)
			{
				Vector2D calculatedPoint(normalizedOrigin.GetX() * i, normalizedOrigin.GetY() * i);

				for (auto boxCollider2D : world->GetCollidersInWorld())
				{
					if (boxCollider2D != nullptr && boxCollider2D->GetOwner()->GetName() != "Player")
					{
						SDL_Point point;
						point.x = calculatedPoint.GetX();
						point.y = calculatedPoint.GetY();
						if (SDL_PointInRect(&point, &boxCollider2D->GetColliderRectangle()))
							return boxCollider2D->GetOwner();
					}
				}
			}
		}

		return nullptr;
	}
}