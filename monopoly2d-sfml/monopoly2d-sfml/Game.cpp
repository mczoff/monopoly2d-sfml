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

	gamewindow = new GameWindow(options->getwidth(),options->getheight(),options->getnameWindow());

	logoservice = new LogoService();
	logoservice->loadlogo("logo / rhorvald.jpg");
	logoservice->showlogo();

	while (gamewindow->isOpen())
	{
		gamewindow->procEvents();

		gamewindow->render();
		gamewindow->clear();
	}

	return 0;
}

