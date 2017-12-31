#pragma once

#include "SFML\Graphics.hpp"

#include "Options.h"

class Background
{
	sf::Image* image;
	sf::Texture* texture;
	sf::Sprite* sprite;
	
	Background(char* i_path);

public:
	
	sf::Sprite* getSprite();

	virtual ~Background();
	static Background* loadBackgroundFromFile(char* i_path);
};

