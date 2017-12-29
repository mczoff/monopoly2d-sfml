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

	while (gamewindow->isOpen())
	{
		gamewindow->add();

		gamewindow->draw();

		gamewindow->procEvents();

		
		gamewindow->render();
		gamewindow->clear();
	}

	return 0;
}

