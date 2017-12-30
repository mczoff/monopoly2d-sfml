#pragma once

#include "GameWindow.h"
#include "Options.h"
#include "LogoService.h"

class Game
{
	Options* options;
	GameWindow* gamewindow;
	LogoService* logoservice;
public:
	Game();
	bool open();
	
	virtual ~Game();
};

