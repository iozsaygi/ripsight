#ifndef WORLD_H
#define WORLD_H

#include "public/engine_entry.h"

namespace engine
{
	// Contains entities and updates the game state frame by frame.
	class World
	{
	public:
		World(EngineEntry* engineEntry);
		World(EngineEntry* engineEntry, bool isActive);

		// Will be called every frame to update components of actors in world.
		void Tick();

	private:
		bool m_IsActive = false;
		EngineEntry* m_EngineEntry = nullptr;

		void ProcessEvents();
		void Render();
	};
}

#endif // !WORLD_H