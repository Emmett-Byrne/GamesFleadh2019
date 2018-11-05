#include "Game.h"
#include <iostream>

#include "Utility.h"

Game::Game() :
	m_window{ sf::VideoMode{ 1920, 1080, 32 }, "TBD"/*, sf::Style::Fullscreen*/},
	m_exitGame{ false },
	m_player(m_resourceMng, m_input/*, m_window*/)
{
	m_window.setVerticalSyncEnabled(true);

	m_plane.setFillColor(sf::Color(0, 51, 0, 255));
	m_plane.setSize(PLANE_SIZE);
	m_plane.setPosition(PLANE_POS);
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	m_input.update();
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_exitGame = true;
		}

		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::A == event.key.code)
			{
				m_input.m_current.A = true;
			}
			if (sf::Keyboard::D == event.key.code)
			{
				m_input.m_current.D = true;
			}
			if (sf::Keyboard::Space == event.key.code)
			{
				m_input.m_current.Space = true;
			}
		}

		if (sf::Event::KeyReleased == event.type)
		{
			if (sf::Keyboard::A == event.key.code)
			{
				m_input.m_current.A = false;
			}
			if (sf::Keyboard::D == event.key.code)
			{
				m_input.m_current.D = false;
			}
			if (sf::Keyboard::Space == event.key.code)
			{
				m_input.m_current.Space = false;
			}
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	m_player.update(t_deltaTime);

	if (m_exitGame)
	{
		m_window.close();
	}
}

void Game::render()
{
	m_window.clear(sf::Color::Black);

	m_window.draw(m_plane);
	m_player.render(m_window);

	m_window.display();
}