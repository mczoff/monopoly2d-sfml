#pragma once

#include "GameWindow.h"
#include "Background.h"

class GameMenu
{
	Background* background;
	GameWindow* gamewindow;
public:

	void show();

	GameMenu(GameWindow* i_gamewindow);
	virtual ~GameMenu();
};

