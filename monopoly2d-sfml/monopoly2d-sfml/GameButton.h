#pragma once

#include "SFML\Graphics.hpp"

class GameButton
{
	sf::Image source_image;
	sf::Texture source_texture;
	sf::Sprite source_sprite;

	sf::Image hover_image;
	sf::Texture hover_texture;
	sf::Sprite hover_sprite;

	sf::Image pressed_image;
	sf::Texture pressed_texture;
	sf::Sprite pressed_sprite;

public:

	void checkClick();
	void setState(bool value);

	GameButton(sf::Vector2f location);
	virtual ~GameButton();
};

