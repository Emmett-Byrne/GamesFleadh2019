#include "GameScreen.h"
#include "Utility.h"


GameScreen::GameScreen(sf::RenderWindow & t_window, Menu & state, Options & t_options, ResourceManager & t_resourceMng, Input & t_input) :
	m_state(state),
	m_options(t_options),
	m_player(t_resourceMng, t_input)
{

	sf::Transform temp;
	temp.translate(0, -500);
	m_renderState.transform = temp;

	sf::Transform tempTrans;
	temp.translate(0, -1200);
	m_renderState.transform = temp;

	// set up the plane
	m_plane.setFillColor(sf::Color(0, 51, 0, 255));
	m_plane.setSize(PLANE_SIZE);
	m_plane.setPosition(PLANE_POS);

}

GameScreen::~GameScreen()
{
}

void GameScreen::processEvents(Xbox360Controller & t_gamepad)
{
	// game.cpp processevents
}

void GameScreen::update(sf::Time t_deltaTime)
{
	m_player.update(t_deltaTime);
}

void GameScreen::render(sf::RenderWindow & t_window)
{
	m_player.render(t_window);
	t_window.draw(m_plane);
}

bool GameScreen::getChangeMenu()
{
	return m_changeMenu;
}

void GameScreen::resetChangeMenu()
{
	m_changeMenu = false;
}