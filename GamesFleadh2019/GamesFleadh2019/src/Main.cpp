#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#pragma comment(lib,"thor-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#pragma comment(lib,"thor.lib") 
#endif 

/// <summary>
/// if we decide to use yaml, we will need the line below
/// MUST be before first include line
/// </summary>
/// #pragma comment(lib,"libyaml-cppmdd") 

#include "Game.h"
#include <cstdlib>
#include <ctime>



/// <summary>
/// main enrtry point
/// </summary>
/// <returns>true</returns>
int main()
{
	std::srand(std::time(nullptr));

	Game game;
	game.run();

	return 1;
}