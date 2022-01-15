#include "Game.h"
#include <iostream>
#undef main

int main()
{
	try {		
		Game game{};
		game.run();
	}
	catch (const std::runtime_error& e) {
		SDL_Log("Unable to initialize SDL: %s", e.what());
		std::cerr << "runtime error: " << e.what(); 
	}
	catch (...) {
		std::cerr << "Unknown exception occured. Exiting.";
	}
	return 0;
}
