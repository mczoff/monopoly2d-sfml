#pragma once

#include "ClickableObject.h"
#include "StaticGraphicObject.h"
#include "SFML\Graphics.hpp"
#include "GameWindow.h"

class MusicVolumeControl
{
	Options* options;
	const int spacevalue = 30;

	sf::Vector2i position;
	ClickableObject* co_down;
	ClickableObject* co_up;
	std::vector<StaticGraphicObject*> volumestate;
	
	void refreshvolumestate();
public:
	
	void setlocation(sf::Vector2i i_location);
	sf::Vector2i getlocation();

	void add(GameWindow* i_gamewindow);

	MusicVolumeControl();
	virtual ~MusicVolumeControl();
};

