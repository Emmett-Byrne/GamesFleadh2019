#pragma once
#include <SFML/Graphics.hpp>

const sf::Vector2f SCREEN_SIZE{ 1920.0f, 1080.0f };
const sf::Vector2f SCREEN_CENTER{ SCREEN_SIZE / 2.0f };
const int PIXELS_TO_METERS{ 30 };
const float FRICTION{ 0.99f };
const sf::Vector2f GRAVITY{ 0.0f, 9.81f * PIXELS_TO_METERS };
const sf::Vector2f PLANE_SIZE{ SCREEN_SIZE.x, 80.0f };
const sf::Vector2f PLANE_POS{ 0.0f, SCREEN_SIZE.y - PLANE_SIZE.y };