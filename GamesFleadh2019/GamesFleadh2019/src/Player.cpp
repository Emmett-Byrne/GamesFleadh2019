#include "Player.h"
#include "Utility.h"
#include <math.h>

/// <summary>
/// note to self:
/// working on double jump
/// </summary>

Player::Player():
	SIZE(30),
	SPEED(10),
	MAX_JUMPS(4),
	MAX_SPEED(SPEED * PIXELS_TO_METERS),
	JUMP_VELO(-12 * PIXELS_TO_METERS),
	STARTING_POS(1920/2.0, PLANE_POS.y)
{
	setupPlayer();

	m_accel = GRAVITY;
}


Player::~Player()
{
}

void Player::processEvents(sf::Event & t_event, Xbox360Controller & t_controller)
{
	if (sf::Event::KeyPressed == t_event.type) //user key press
	{
		if (sf::Keyboard::A == t_event.key.code)
		{
			m_left = true;
		}
		if (sf::Keyboard::D == t_event.key.code)
		{
			m_right = true;
		}
		if (sf::Keyboard::Space == t_event.key.code && !m_jump)
		{
			if (!m_jump && m_jumpIndex < MAX_JUMPS)
			{
				m_jumpIndex++;
				m_airborn = true;
				if (m_velocity.y > 0)
				{
					m_velocity.y = JUMP_VELO / m_jumpIndex;
				}
				else
				{
					m_velocity.y += JUMP_VELO / m_jumpIndex;
				}
			}

			m_jump = true;
		}
	}

	if (sf::Event::KeyReleased == t_event.type)
	{
		if (sf::Keyboard::A == t_event.key.code)
		{
			m_left = false;
		}
		if (sf::Keyboard::D == t_event.key.code)
		{
			m_right = false;
		}
		if (sf::Keyboard::Space == t_event.key.code)
		{
			m_jump = false;
		}
	}
}

void Player::update(sf::Time t_deltaTime)
{
	//handleKeyPress();
	handleMovement(t_deltaTime.asSeconds());
	
	m_speedTxt.setString("Speed: " + std::to_string(static_cast<int>(m_velocity.x)));

}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
	t_window.draw(m_speedTxt);
}

void Player::setupPlayer()
{
	m_body.setSize(sf::Vector2f(SIZE, SIZE));
	//m_body.setOrigin(sf::Vector2f(SIZE / 2.0, SIZE / 2.0));
	m_body.setPosition(STARTING_POS);
	m_body.setFillColor(sf::Color(0, 0, 153, 255));
	
	m_position = m_body.getPosition();

	m_velocity = sf::Vector2f(0.0f, 0.0f);

	m_font.loadFromFile(".//assets//fonts//ariblk.ttf");
	m_speedTxt.setFont(m_font);

	m_speedTxt.setString("Speed: ");
	m_speedTxt.setPosition(sf::Vector2f(50.f, 50.f));
}

void Player::handleKeyPress()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_left = true;
	}
	else
	{
		m_left = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_right = true;
	}
	else
	{
		m_right = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_jump = true;
		if (m_airborn && !m_doubleJump)
		{
			m_doubleJump = true;
		}
	}
	else
	{
		m_jump = false;
	}
}

void Player::handleMovement(float t_time)
{
	if (m_right)
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
	
	if (m_left)
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


	m_position += m_velocity * t_time + (0.5f * m_accel * (t_time * t_time));
	m_velocity += m_accel * t_time;

	//if (m_airborn && m_doubleJump)
	//{
	//	m_velocity.y = DOUBLE_JUMP;
	//}
	
	if (m_position.y + SIZE >= PLANE_POS.y)
	{
		m_position.y = PLANE_POS.y - SIZE;
		m_velocity.y = 0.0f;
		m_airborn = false;
		m_jumpIndex = 0;

		//if (m_jump)
		//{
		//	m_velocity.y = JUMP_VELO;
		//}
	}
	//else if(m_jump && m_jumpIndex < MAX_JUMPS)
	//{
	//	m_velocity.y = JUMP_VELO / m_jumpIndex;
	//}

	m_body.setPosition(m_position);
}
