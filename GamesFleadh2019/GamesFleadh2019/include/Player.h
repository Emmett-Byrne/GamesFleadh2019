#pragma once

#include "XBOX360CONTROLLER.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "XBOX360CONTROLLER.h"
#include "Input.h"
#include "ResourceManager.h"
#include "AnimatedSprite.h"
#include <FSM.h>

class Player
{
public:
	Player(ResourceManager & t_resources, Input & t_input);

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow & t_window);

private:
	// instantiate events
	Idle idle;
	Run run;
	Jump jump;

	// functions
	void setupPlayer();
	void handleMovement(float t_time);
	void setAnimRect(AnimatedSprite& anim, int frames, int width, int height, int pos);
	void updateSize();
	void addForce(Vector2f t_force);
	void jumpHandler();

	// consts
	const int MASS;
	const int SIZE;
	const int SPEED;
	const int MAX_SPEED;
	const int JUMP_VELO;
	const int MAX_JUMPS;
	const sf::Vector2f STARTING_POS;
	const int MAX_FRAMES;
	const float TIME_PER_FRAME;
	
	// variables
	RectangleShape m_body;
	Vector2f m_position;
	Vector2f m_velocity;
	Vector2f m_accel;
	int sizeWidth;
	int sizeHeight;

	ResourceManager & m_resourceMng;
	Input & m_input;

	bool m_airborn = false;

	Text m_speedTxt;
	Font m_font;
};

