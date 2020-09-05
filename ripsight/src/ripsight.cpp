#include "engine.h"

int main(int argc, char* argv[])
{
	auto engineEntry = new engine::EngineEntry("Ripsight", 800, 600, 60);
	auto world = engine::World(engineEntry, true);
	world.Tick();

	delete engineEntry;
	return 0;
}