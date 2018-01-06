#pragma once

#include "SFML\Graphics.hpp"
#include "Options.h"

class StaticGraphicObject 
{
	sf::Image* image;
	sf::Texture* texture;
	sf::Sprite* sprite;

protected:
	StaticGraphicObject(char* i_path);
public:

	void setSize(sf::Vector2i i_size);
	void setLocation(sf::Vector2i i_location);

	sf::Sprite* getSprite();
	static StaticGraphicObject* loadBackgroundFromFile(char* i_path);
	virtual ~StaticGraphicObject();
};

