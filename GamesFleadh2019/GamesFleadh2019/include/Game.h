#pragma once

#include <SFML/Graphics.hpp>

#include <Thor/Math.hpp>
#include <Thor/Vectors.hpp>

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
	ResourceManager m_resourceMng; // resource manager

	// const/static
	

	// functions
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	// variables
	Xbox360Controller m_controller;
	Input m_input;
	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game


	Player m_player;

	sf::RectangleShape m_plane;

};

