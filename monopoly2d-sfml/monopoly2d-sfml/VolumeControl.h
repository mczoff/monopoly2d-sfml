#pragma once

#include "ClickableObject.h"
#include "StaticGraphicObject.h"
#include "SFML\Graphics.hpp"
#include "GameWindow.h"

class VolumeControl
{
private:
	const int spacevalue = 30;

	sf::Vector2i position;
	ClickableObject* co_down;
	ClickableObject* co_up;
	std::vector<StaticGraphicObject*> volumestate;

protected:
	void clearState();
	void createState(int mid);
	virtual void refreshvolumestate() = 0;

public:

	ClickableObject* getco_down();
	ClickableObject* getco_up();
	int getspacevalue();

	void setlocation(sf::Vector2i i_location);
	sf::Vector2i getposition();

	void add(GameWindow* i_gamewindow);

	VolumeControl();
	virtual ~VolumeControl();
};

