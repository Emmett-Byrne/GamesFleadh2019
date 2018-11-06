#pragma once

#include <SFML/Graphics.hpp>
#include "Frame.h"
#include "VLayout.h"
#include "TextButton.h"
#include "button.h"
#include "CheckButton.h"
#include "RadioButton.h"
#include "Slider.h"
#include "XBOX360CONTROLLER.h"
#include "States.h"

#include <Thor/Math.hpp>
#include <Thor/Vectors.hpp>
#include "ResourceManager.h"

#include "MainMenu.h"
#include "OptionMenu.h"
#include "SplashScreen.h"
#include "LicenseScreen.h"
#include "GameScreen.h"
#include "CreditsScreen.h"


class Game
{
public:Game();
	   ~Game();
	   /// <summary>
	   /// main method for game
	   /// </summary>
	   void run();

private:
	ResourceManager m_resourceMng; // resource manager
	Xbox360Controller m_controller;
	Input m_input;

	// const/static
	

	// functions
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void processScreenEvents();

	// variables
	sf::RenderStates state;
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message

	bool m_exitGame; // control exiting game

	Menu m_currentMenu;
	bool m_changingMenu;

	SplashScreen m_splashScreen;
	LicenseScreen m_licenseScreen;
	MainMenu m_mainMenu;
	OptionMenu m_optionMenu;
	CreditsScreen m_creditsScreen;
	GameScreen m_gameScreen;

	Options m_options;

};

