#pragma once



#include "GameWindow.h"
#include "GameMenu.h"
#include "Options.h"
#include "LogoService.h"

class Game
{
	Options* options;
	GameWindow* gamewindow;
	LogoService* logoservice;
	GameMenu* gamemenu;
public:
	Game();
	bool open();
	
	virtual ~Game();
};

