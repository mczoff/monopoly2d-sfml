#pragma once

#include "GameButton.h"
#include "StaticGraphicObject.h"
#include "SFML\Graphics.hpp"
#include "GameWindow.h"
#include "IDrawableControl.h"

class VolumeControl : public IDrawableControl
{
private:
	const int spacevalue = 30;

	sf::Vector2i position;

	GameButton* bt_down;
	GameButton* bt_up;

	std::vector<StaticGraphicObject*> volumestate;

protected:
	void clearState();
	void createState(int mid);
	virtual void refreshvolumestate() = 0;

public:

	ClickableObject* getbt_down();
	ClickableObject* getbt_up();
	int getspacevalue();

	void setlocation(sf::Vector2i i_location);
	sf::Vector2i getlocation();

	void add(GameWindow* i_gamewindow);
	void playbuttonssound();

	VolumeControl();
	virtual ~VolumeControl();
};

