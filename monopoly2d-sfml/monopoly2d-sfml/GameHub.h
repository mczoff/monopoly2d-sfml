#pragma once



#include "GameWindow.h"
#include "GameMenu.h"
#include "Options.h"
#include "LogoService.h"

//LIST TODO
// TODO: getco_down()->refreshState(); ->  getco_down()->refreshState();
// TODO: NUMBERS FONTS FOR NUMERIC AND RESOLUTION CONTROLS
// TODO: IClickabel with doisclick and isclick()
//
//


class GameHub
{
	Options* options;
	GameWindow* gamewindow;
	LogoService* logoservice;
	GameMenu* gamemenu;

public:
	GameHub();
	bool open();
	
	virtual ~GameHub();
};

