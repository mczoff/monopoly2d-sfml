#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

bool Game::open()
{
	options = Options::getInstance();
	options->loadoptions("config.ini");
	gamewindow = GameWindow::createInstance(options->getwidth(),options->getheight(),options->getnameWindow(),options->getStyleFlag());
	logoservice = new LogoService();
	gamemenu = new GameMenu();

	//logoservice->loadlogo("logo/kt.jpg");
	//logoservice->showlogo(gamewindow, 0.3, 2);
	//logoservice->loadlogo("logo/ptf.jpg");
	//logoservice->showlogo(gamewindow, 0.3, 2);
	//logoservice->loadlogo("logo/rhorvald.jpg");
	//logoservice->showlogo(gamewindow, 0.3, 2);

	gamemenu->show();
	


	Options::getInstance()->saveoptions("config.ini");

	return 0;
}

