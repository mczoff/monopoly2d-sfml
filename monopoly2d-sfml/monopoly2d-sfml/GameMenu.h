#pragma once

#include "GameWindow.h"
#include "Background.h"
#include "MusicService.h"
#include "Options.h"

class GameMenu
{
	Options* options;
	Background* background;
	GameWindow* gamewindow;
	MusicService* musicservice;
public:

	void show();

	GameMenu(GameWindow* i_gamewindow);
	virtual ~GameMenu();
};

