#ifndef RAYCAST_2D_H
#define RAYCAST_2D_H

#include "core/common/actor.h"
#include "core/common/world_manager.h"
#include "ray.h"

namespace engine
{
	Actor* Raycast2D(Ray ray);
}

#endif // !RAYCAST_2D_H