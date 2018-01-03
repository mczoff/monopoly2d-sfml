#pragma once

#include "GameWindow.h"
#include "Background.h"
#include "MusicService.h"
#include "Options.h"
#include "GameButton.h"

#include "StateObject.h"

class GameMenu
{
	Options* options;
	Background* background;
	GameWindow* gamewindow;

	GameButton* bt_newGame;
	GameButton* bt_options;
	GameButton* bt_exit;

	MusicService* musicservice;

public:

	void show();

	GameMenu(GameWindow* i_gamewindow);
	virtual ~GameMenu();
};

