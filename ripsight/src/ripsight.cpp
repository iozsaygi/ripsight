#include "engine.h"

int main(int argc, char* argv[])
{
	// Initialize the engine.
	engine::EngineEntry* engineEntry = new engine::EngineEntry("Ripsight",
		800, 600, 60);

	// Create temporary world and enter the loop.
	engine::World world = engine::World(engineEntry, true);
	world.Tick();

	delete engineEntry;
	return 0;
}