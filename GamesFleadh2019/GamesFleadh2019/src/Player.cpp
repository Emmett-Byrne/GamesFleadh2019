#include "Player.h"



Player::Player():
	SIZE(10),
	STARTING_POS(1920/2.0, 1080/2.0)
{
	m_body.setSize(sf::Vector2f(SIZE, SIZE));
	m_body.setOrigin(sf::Vector2f(SIZE / 2.0, SIZE / 2.0));
	m_body.setPosition(STARTING_POS);
	m_body.setFillColor(sf::Color::Green);

	m_position = m_body.getPosition();
}


Player::~Player()
{
}

void Player::processEvents(Xbox360Controller & t_controller)
{
}

void Player::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_position.x--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_position.x++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_position.y--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_position.y++;
	}


	m_body.setPosition(m_position);
}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
}
