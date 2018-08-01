#pragma once

#include "XBOX360CONTROLLER.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	void processEvents(sf::Event & t_event, Xbox360Controller & t_controller); 
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow & t_window);

private:
	// functions
	void setupPlayer();
	void handleKeyPress();
	void handleMovement(float t_time);

	// consts
	const int SIZE;
	const int SPEED;
	const int MAX_SPEED;
	const int JUMP_VELO;
	const int MAX_JUMPS;
	const sf::Vector2f STARTING_POS;

	// variables
	sf::RectangleShape m_body;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_accel;

	int m_jumpIndex{ 0 };

	bool m_left = false;
	bool m_right = false;
	bool m_jump = false;
	bool m_doubleJump = false;
	bool m_airborn = false;

	sf::Text m_speedTxt;
	sf::Font m_font;
	
};

