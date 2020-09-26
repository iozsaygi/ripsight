// Only include from client applications.
#ifndef ENGINE_H
#define ENGINE_H

// blueprints
#include "core/blueprints/components/audio_player.h"
#include "core/blueprints/components/box_collider_2D.h"
#include "core/blueprints/components/sprite_renderer.h"
#include "core/blueprints/components/text.h"
#include "core/blueprints/components/transform.h"

// core
#include "core/common/actor.h"
#include "core/common/component.h"
#include "core/common/world.h"
#include "core/common/world_manager.h"
#include "core/event_system/input.h"
#include "core/event_system/keycode.h"
#include "core/event_system/mouse_state.h"

// math
#include "math/vector2D.h"

// physics
#include "physics/ray.h"
#include "physics/raycast2D.h"

// public
#include "public/color.h"
#include "public/engine_entry.h"

#endif // !ENGINE_H