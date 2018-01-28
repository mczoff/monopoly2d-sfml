#pragma once



#include "GameWindow.h"
#include "GameMenu.h"
#include "Options.h"
#include "LogoService.h"

//LIST TODO
// TODO: getco_down()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow())); ->  getco_down()->refreshState();
// TODO: NUMBERS FONTS FOR NUMERIC AND RESOLUTION CONTROLS
// TODO: IClickabel with doisclick and isclick()
//
//


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

