#pragma once

#include "Frame.h"
#include <SFML/Graphics.hpp>
#include "VLayout.h"
#include "TextButton.h"
#include "button.h"
#include "CheckButton.h"
#include "RadioButton.h"
#include "Slider.h"
#include "XBOX360CONTROLLER.h"
#include "States.h"
#include "ResourceManager.h"
#include "Input.h"
#include "Player.h"

class GameScreen
{
public:
	/// <summary>
	/// default constructor
	/// </summary>
	/// <param name="t_font">a reference to a font</param>
	/// <param name="t_window">reference to the render window for the frame</param>
	/// <param name="state">reference to the game state</param>
	/// <param name="t_options">a reference to the game settings in the options screen</param>
	GameScreen(sf::RenderWindow & t_window, Menu & state, Options & t_options, ResourceManager & t_resourceMng, Input & t_input);
	~GameScreen();

	/// <summary>
	/// processes game events
	/// </summary>
	/// <param name="pad"> reference to the game controller</param>
	/// <param name="t_event">an event passed in from game.cpp</param>
	void processEvents(Xbox360Controller & pad);

	/// <summary>
	/// updates all objects in this class
	/// </summary>
	/// <param name="t_deltaTime">time since last update</param>
	void update(sf::Time t_deltaTime);

	/// <summary>
	/// function that renders all drawable objects
	/// </summary>
	/// <param name="t_window">reference to the main window</param>
	void render(sf::RenderWindow & t_window);

	bool getChangeMenu();
	/// <summary>
	/// resets the m_changeMenu variable
	/// </summary>
	void resetChangeMenu();

private:
	Player m_player;
	sf::RectangleShape m_plane;

	Menu & m_state; //reference to the state holding the current menu
	Menu m_nextState;

	Options & m_options;

	sf::RenderStates m_renderState;

	bool m_changeMenu;
};

