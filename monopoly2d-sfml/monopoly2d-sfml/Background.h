#pragma once

#include "SFML\Graphics.hpp"
#include "StaticGraphicObject.h"
#include "Options.h"

class Background 
{
	StaticGraphicObject* object;

	Background(char* i_path);

	StaticGraphicObject* getobject();


public:
	
	sf::Sprite* getSprite();

	virtual ~Background();
	static Background* loadBackgroundFromFile(char* i_path);
};

