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

	gamewindow = new GameWindow(options->getwidth(),options->getheight(),options->getnameWindow(),options->getStyleFlag());
	logoservice = new LogoService();

	//TODO Logo all videomodes
	logoservice->loadlogo("logo/rhorvald.jpg");
	logoservice->showlogo(gamewindow, 0.3, 2);

	logoservice->loadlogo("logo/rhorvald.jpg");
	logoservice->showlogo(gamewindow, 0.3, 2);


	while (gamewindow->isOpen())
	{
		
		gamewindow->procEvents();

		gamewindow->render();
		gamewindow->clear();
	
	}

	return 0;
}

