#pragma once

#include "SFML\Graphics.hpp"

class Logo
{
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Logo();
	virtual ~Logo();
};

