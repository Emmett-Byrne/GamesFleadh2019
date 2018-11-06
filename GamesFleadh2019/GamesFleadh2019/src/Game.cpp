#include "Game.h"
#include <iostream>

#include "Utility.h"

Game::Game() :
	m_window{ sf::VideoMode{ 1920, 1080, 32 }, "TBD"/*, sf::Style::Fullscreen*/ },
	m_exitGame{ false },
	m_currentMenu(Menu::StateSplash),
	m_gameScreen(m_window, m_currentMenu, m_options, m_resourceMng, m_input),
	m_mainMenu(m_resourceMng.getFont(FontID::ARIBLK), m_window, m_currentMenu, m_options),
	m_optionMenu(m_resourceMng.getFont(FontID::ARIBLK), m_window, m_currentMenu, m_options),
	m_creditsScreen(m_resourceMng.getFont(FontID::ARIBLK), m_window, m_currentMenu, m_options),
	m_licenseScreen(m_currentMenu),
	m_splashScreen(m_currentMenu)
{
	m_window.setVerticalSyncEnabled(true);

	m_options.musicVol = 100;
	m_options.soundVol = 100;
	m_options.mute = false;
	m_options.animSpeed = 50;
	m_options.fontSize = 2;

	m_splashScreen.transitionIn();
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
	processScreenEvents();
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
	switch (m_currentMenu)
	{
	case Menu::StateSplash:
		if (m_changingMenu)
		{
			m_splashScreen.transitionIn();
		}
		m_splashScreen.update(t_deltaTime);
		m_changingMenu = m_splashScreen.getChengeMenu();
		m_splashScreen.resetChangeMenu();
		break;
	case Menu::StateLicense:
		if (m_changingMenu)
		{
			m_licenseScreen.transitionIn();
		}
		m_licenseScreen.update(t_deltaTime);
		m_changingMenu = m_licenseScreen.getChengeMenu();
		m_licenseScreen.resetChangeMenu();
		break;
	case StateMainMenu:
		if (m_changingMenu)
		{
			m_mainMenu.transitionIn();
		}
		m_mainMenu.update(t_deltaTime);
		m_changingMenu = m_mainMenu.getChengeMenu();
		m_mainMenu.resetChangeMenu();
		break;
	case StateOptions:
		if (m_changingMenu)
		{
			m_optionMenu.transitionIn();
		}
		m_optionMenu.update(t_deltaTime);
		m_changingMenu = m_optionMenu.getChangeMenu();
		m_optionMenu.resetChangeMenu();
		break;
	case StateGame:
		m_gameScreen.update(t_deltaTime);
		break;
	case StateCredits:
		if (m_changingMenu)
		{
			m_creditsScreen.transitionIn();
		}
		m_creditsScreen.update(t_deltaTime);
		m_changingMenu = m_creditsScreen.getChengeMenu();
		m_creditsScreen.resetChangeMenu();
		break;
	case StateQuit:
		break;
	default:
		break;
	}


	if (m_exitGame)
	{
		m_window.close();
	}
}

void Game::render()
{
	m_window.clear(sf::Color::Black);

	switch (m_currentMenu)
	{
	case StateSplash:
		m_splashScreen.render(m_window);
		break;
	case StateLicense:
		m_licenseScreen.render(m_window);
		break;
	case StateMainMenu:
		m_mainMenu.render(m_window);
		break;
	case StateOptions:
		m_optionMenu.render(m_window);
		break;
	case StateGame:
		m_gameScreen.render(m_window);
		break;
	case StateCredits:
		m_creditsScreen.render(m_window);
		break;
	case StateQuit:
		break;
	default:
		break;
	}

	m_window.display();
}

void Game::processScreenEvents()
{
	switch (m_currentMenu)
	{
	case StateSplash:
		m_splashScreen.processEvents(m_controller);
		break;
	case StateLicense:
		m_licenseScreen.processEvents(m_controller);
		break;
	case StateMainMenu:
		m_mainMenu.processEvents(m_controller);
		break;
	case StateOptions:
		m_optionMenu.processEvents(m_controller);
		break;
	case StateCredits:
		m_creditsScreen.processEvents(m_controller);
		break;
	case StateQuit:
		break;
	default:
		break;
	}
}
