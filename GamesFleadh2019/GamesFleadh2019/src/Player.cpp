#include "Player.h"
#include "Utility.h"
#include <math.h>
#include "Tinyc2Debug.hpp"

Player::Player(ResourceManager & t_resources, Input & t_input/*, sf::RenderWindow & t_window*/) :
	m_resourceMng(t_resources),
	//m_window(t_window),
	MASS(10),
	SIZE(30),
	SPEED(10),
	MAX_JUMPS(4),
	MAX_SPEED(SPEED * PIXELS_TO_METERS),
	JUMP_VELO(-12 * PIXELS_TO_METERS),
	STARTING_POS(1920 / 2.0, PLANE_POS.y),
	MAX_FRAMES(29),
	TIME_PER_FRAME(160.0f),
	m_input(t_input)
{
	FSM::start();
	setupPlayer();

	m_accel = GRAVITY;
}


void Player::update(sf::Time t_deltaTime)
{
	handleMovement(t_deltaTime.asSeconds());

	m_speedTxt.setString("Speed: " + std::to_string(static_cast<int>(m_velocity.y)));

	FSM::updateAnim();
}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
	t_window.draw(m_speedTxt);

	FSM::getAnim()->setTextureRect(FSM::getAnim()->getFrame(FSM::getAnim()->getCurrentFrame()));
	t_window.draw(*FSM::getAnim());
}

void Player::setupPlayer()
{
	m_body.setFillColor(sf::Color(0, 0, 153, 255));
	m_velocity = sf::Vector2f(0.0f, 0.0f);

	m_font.loadFromFile(".//assets//fonts//ariblk.ttf");
	m_speedTxt.setFont(m_font);

	m_speedTxt.setString("Speed: ");
	m_speedTxt.setPosition(sf::Vector2f(50.f, 50.f));

	FSM::getIdleRef().setTexture(m_resourceMng.getTexture(TextureID::PLAYER_SHEET));
	setAnimRect(FSM::getIdleRef(), 8, 64, 128, 0);
	FSM::getIdleRef().setTime(Time(seconds(8.0f / 60.0f)));
	FSM::getIdleRef().setOrigin(64 / 2, 128 / 2);

	FSM::getRunRef().setTexture(m_resourceMng.getTexture(TextureID::PLAYER_SHEET));
	setAnimRect(FSM::getRunRef(), 8, 128, 128, 128);
	FSM::getRunRef().setTime(Time(seconds(8.0f / 60.0f)));
	FSM::getRunRef().setOrigin(128 / 2, 128 / 2);

	updateSize();
	m_position = STARTING_POS;
}


void Player::handleMovement(float t_time)
{
	if (m_input.m_current.A || m_input.m_current.D)
	{
		FSM::dispatch(run);
		updateSize();
	}
	else
	{
		FSM::dispatch(idle);
		updateSize();
	}

	if (m_input.m_current.D)
	{
		if (m_velocity.x + SPEED < MAX_SPEED)
		{
			m_velocity.x += SPEED;

			if (m_velocity.x > MAX_SPEED)
			{
				m_velocity.x = MAX_SPEED;
			}
		}
	}
	
	if (m_input.m_current.A)
	{
		if (m_velocity.x - SPEED > -MAX_SPEED)
		{
			m_velocity.x -= SPEED;

			if (m_velocity.x < -MAX_SPEED)
			{
				m_velocity.x = -MAX_SPEED;
			}
		}
	}

	if (m_input.m_current.Space)
	{
		jumpHandler();
	}

	
	sf::Vector2f unitVelo;
	if (m_velocity.x < 0 || m_velocity.x > 0)
	{
		unitVelo.x = m_velocity.x / sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y);
	}

	// if in air, no friction on the x axis
	if (m_airborn)
	{
		m_accel = GRAVITY;
	}
	// if on ground, there is friction
	else
	{
		m_accel.x = -1.0f * FRICTION * GRAVITY.y * unitVelo.x;
	}

	if (m_velocity.x < 3.5f && m_velocity.x > -3.5f)
	{
		m_velocity.x = 0;
	}

	m_velocity += m_accel * t_time;
	m_position += m_velocity * t_time + (0.5f * m_accel * (t_time * t_time));

	if (m_position.y + sizeHeight / 2 >= PLANE_POS.y)
	{
		m_position.y = PLANE_POS.y - sizeHeight / 2;
		m_velocity.y = 0.0f;
		m_airborn = false;
	}

	m_body.setPosition(m_position);
	FSM::getAnim()->setPosition(m_position);
}

void Player::setAnimRect(AnimatedSprite & anim, int frames, int width, int height, int pos)
{
	for (int i = 0; i < frames; i++)
	{
		IntRect rec(0 + width * i, pos, width, height);
		anim.addFrame(rec);
	}
}

void Player::updateSize()
{
	sizeWidth = FSM::getAnim()->getFrame(FSM::getAnim()->getCurrentFrame()).width;
	sizeHeight = FSM::getAnim()->getFrame(FSM::getAnim()->getCurrentFrame()).height;
	m_body.setSize(sf::Vector2f(sizeWidth, sizeHeight));
	m_body.setOrigin(sf::Vector2f(sizeWidth / 2, sizeHeight / 2));
}

void Player::addForce(Vector2f t_force)
{
	m_accel += t_force;
}

void Player::jumpHandler()
{
	m_airborn = true;
	if (m_velocity.y > 0)
	{
		addForce(Vector2f(0, -JUMP_VELO));
	}
	else
	{
		addForce(Vector2f(0, -JUMP_VELO));
	}
}


