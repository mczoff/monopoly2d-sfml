#pragma once

#include "GameWindow.h"
#include "Options.h"

class Game
{
	Options* options;
	GameWindow* gamewindow;
public:
	Game();
	bool open();
	
	virtual ~Game();
};

