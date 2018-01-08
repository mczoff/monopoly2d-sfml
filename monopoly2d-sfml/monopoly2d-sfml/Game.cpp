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



	gamemenu->show();

	return 0;
}

