#pragma once

#include "IShowable.h"
#include "GameButton.h"
#include "SFML\Graphics.hpp"
#include "NumericControl.h"
#include "Background.h"
#include "Game.h"

class GameCreatorMenu : public IShowable
{
	int maxvalueingame = 9;

	Background* background;

	Game* game;

	NumericControl* nc_players;
	NumericControl* nc_bots;

	Options* options;
	GameWindow* gamewindow;

	GameButton* bt_back;
	GameButton* bt_create;

	StaticGraphicObject* cntbots;
	StaticGraphicObject* cntplayers;
	StaticGraphicObject* man3;
	StaticGraphicObject* man4;

public:

	void show();

	GameCreatorMenu();
	virtual ~GameCreatorMenu();
};

