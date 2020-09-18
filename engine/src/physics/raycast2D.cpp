#include <SDL.h>
#include "math/vector2D.h"
#include "raycast2D.h"
#include <iostream>

namespace engine
{
	Actor* Raycast2D(Ray ray)
	{
		auto world = WorldManager::GetActiveWorld();
		if (world != nullptr)
		{
			SDL_Point origin;
			origin.x = ray.GetOrigin().GetX();
			origin.y = ray.GetOrigin().GetY();

			for (int i = 0; i < ray.GetLength(); i++)
			{
				for (auto boxCollider2D : world->GetCollidersInWorld())
				{
					// This is a simple hack? Add layer system later on.
					if (boxCollider2D != nullptr && boxCollider2D->GetOwner()->GetName() != "Player" && 
						boxCollider2D->GetIsEnabled())
					{
						if (SDL_PointInRect(&origin, &boxCollider2D->GetColliderRectangle()))
							return boxCollider2D->GetOwner();
					}
				}

				origin.x += i * ray.GetDirection().GetNormalized().GetX();
				origin.y += i * ray.GetDirection().GetNormalized().GetY();
			}
		}

		return nullptr;
	}
}