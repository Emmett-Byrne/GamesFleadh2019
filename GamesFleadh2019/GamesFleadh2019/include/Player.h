#pragma once

#include "XBOX360CONTROLLER.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	void processEvents(Xbox360Controller & t_controller); 
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow & t_window);

private:
	sf::RectangleShape m_body;
	const int SIZE;
	const sf::Vector2f STARTING_POS;
	sf::Vector2f m_position;
};

