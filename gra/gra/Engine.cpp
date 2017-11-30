#include "Engine.h"


Engine::Engine(Level &level_):level(level_)
{
	
}


Engine::~Engine()
{
}

void Engine::game()
{


}
void Engine::update()
{
	level.update();
	player.update();
}

