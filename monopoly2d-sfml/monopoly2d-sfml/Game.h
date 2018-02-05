#pragma once

#include "IShowable.h"
#include "StateGame.h"
#include "GameWindow.h"
#include "Background.h"
#include "GameComponentBuilder.h"
#include "StaticGraphicObject.h"

class Game : public IShowable
{
	GameWindow* gamewindow;

	Background* background;
	StaticGraphicObject* board;

	int c_gamblers;
	int c_players;
	int c_bots;

	int mode;

	GameComponentBuilder gamecomponentbuilder;

public:
	void show();

	Game(int ic_players, int ic_bots);
	virtual ~Game();
};

