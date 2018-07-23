#pragma once

#include <SFML/Graphics.hpp>
#include <Thor/Math.hpp>
#include "ResourceManager.h"
#include "Player.h"

class Game
{
public:Game();
	   ~Game();
	   /// <summary>
	   /// main method for game
	   /// </summary>
	   void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

	ResourceManager m_resourceMng; // resource manager

	Player m_player;

};

