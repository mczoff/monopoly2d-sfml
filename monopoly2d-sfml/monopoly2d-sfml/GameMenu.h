#pragma once

#include "GameWindow.h"
#include "Background.h"
#include "MusicService.h"
#include "Options.h"
#include "GameButton.h"
#include "ExitCommand.h"
#include "StateObject.h"
#include "StaticGraphicObject.h"
#include "OpenOptionsCommand.h"

class GameMenu
{
	StaticGraphicObject* man;

	Options* options;
	Background* background;
	GameWindow* gamewindow;

	WindowCommand* exitcommand;
	WindowCommand* openoptionscommand;

	GameButton* bt_newGame;
	GameButton* bt_options;
	GameButton* bt_exit;

	MusicService* musicservice;

public:
	void show();

	GameMenu();
	virtual ~GameMenu();
};

