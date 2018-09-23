#pragma once

#include "XBOX360CONTROLLER.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "XBOX360CONTROLLER.h"
#include "ResourceManager.h"

class Player
{
	enum class ANIM_STATE
	{
		IDLE,
		RUN
	};

public:
	Player(ResourceManager & t_resources/*, sf::RenderWindow & t_window*/);
	~Player();

	void processEvents(sf::Event & t_event, Xbox360Controller & t_controller); 
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow & t_window);

private:
	// functions
	void setupPlayer();
	void handleKeyPress();
	void handleMovement(float t_time);
	void handleAnimation(float t_time);
	void doIdleAnim(float t_time);
	void doRunAnim();

	// consts
	const int SIZE;
	const int SPEED;
	const int MAX_SPEED;
	const int JUMP_VELO;
	const int MAX_JUMPS;
	const sf::Vector2f STARTING_POS;
	const int MAX_FRAMES;
	const float TIME_PER_FRAME;
	
	// variables
	sf::RectangleShape m_body;
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_accel;
	ANIM_STATE m_animStates;

//	sf::RenderWindow & m_window;
	ResourceManager & m_resourceMng;
	sf::Sprite m_player;

	int m_jumpIndex{ 0 };
	int m_frameNum{ 0 };
	float m_frameTime{ 0.0f };

	bool m_left = false;
	bool m_right = false;
	bool m_jump = false;
	bool m_doubleJump = false;
	bool m_airborn = false;

	sf::Text m_speedTxt;
	sf::Font m_font;
	
};

