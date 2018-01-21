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
	sf::Vector2i getsize();
	void setSize(sf::Vector2i i_size);
	void setPosition(sf::Vector2i i_location);

	sf::Sprite* getSprite();
	static StaticGraphicObject* loadFromFile(char* i_path);
	virtual ~StaticGraphicObject();
};

