#pragma once

#include "IShowable.h"
#include "GameButton.h"
#include "Background.h"
#include "GameWindow.h"
#include "Options.h"
#include "StaticGraphicObject.h"
#include "ShowCommand.h"
#include "GameCreatorMenu.h"

class GameSelectMenu : public IShowable
{
	Background* background;

	GameCreatorMenu* gamecreatormenu;

	StaticGraphicObject* oman;
	StaticGraphicObject* ogirl;

	Options* options;
	GameWindow* gamewindow;
	
	ICommand* showoptionscommand;

	GameButton* bt_newgame;
	GameButton* bt_continuegame;
	GameButton* bt_back;
public:
	
	void show();

	GameSelectMenu();
	virtual ~GameSelectMenu();
};

