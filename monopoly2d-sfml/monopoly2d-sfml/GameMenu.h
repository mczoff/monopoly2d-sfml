#pragma once

#include "GameWindow.h"
#include "Background.h"
#include "MusicService.h"
#include "Options.h"
#include "GameButton.h"
#include "ExitCommand.h"
#include "StateObject.h"
#include "StaticGraphicObject.h"
#include "ShowCommand.h"
#include "OptionsMenu.h"
#include "GameCreatorMenu.h"

class GameMenu : public IShowable
{
	OptionsMenu* optionsmenu;
	GameCreatorMenu* gamecreatormenu;

	StaticGraphicObject* man;

	Options* options;
	Background* background;
	GameWindow* gamewindow;

	ICommand* exitcommand;
	ICommand* showoptionscommand;
	ICommand* showgamecreatormenucommand;

	GameButton* bt_newGame;
	GameButton* bt_options;
	GameButton* bt_exit;

	MusicService* musicservice;

public:
	void show();

	GameMenu();
	virtual ~GameMenu();
};

