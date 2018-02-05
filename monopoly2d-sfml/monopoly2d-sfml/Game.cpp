#include "Game.h"

Game::Game(int ic_players, int ic_bots): 
	c_players(ic_players),
	c_bots(ic_bots),
	c_gamblers(ic_players + ic_bots)
{
	gamewindow = GameWindow::getInstance();
	background = Background::loadFromFile("src/monopoly/background.png");
	board = gamecomponentbuilder.buildBoard();
}

Game::~Game()
{ 
	
}


void Game::show()
{

	while (gamewindow->isOpen())
	{
		gamewindow->add(background->getSizebleSprite());
		gamewindow->add(board->getSprite());
		

		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();
	}
}
