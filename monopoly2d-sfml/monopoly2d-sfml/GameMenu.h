#pragma once

#include "GameWindow.h"
#include "Background.h"
#include "MusicService.h"
#include "Options.h"
#include "GameButton.h"
class GameMenu
{
	Options* options;
	Background* background;
	GameWindow* gamewindow;
	GameButton* bt_newGame;
	MusicService* musicservice;

public:

	void show();

	GameMenu(GameWindow* i_gamewindow);
	virtual ~GameMenu();
};

