#include "GameMenu.h"



GameMenu::GameMenu(GameWindow* i_gamewindow)
{
	//TODO: PATH TO BACKGROUND IMAGE
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png"); 
	gamewindow = i_gamewindow;
	musicservice = new MusicService();
	options = Options::getInstance();
	bt_newGame = new GameButton(sf::Vector2i(100, 100), "src/menu/snewgame.png", "src/menu/hnewgame.png", "src/menu/pnewgame.png");
}


GameMenu::~GameMenu()
{
	delete background;
	delete musicservice;
	delete bt_newGame;
}

void GameMenu::show()
{
	//
	options->setmusicvolume(10);
	//
	musicservice->openFromFile("src/menu/fon.wav");
	musicservice->setvolume(options->getmusicvolume());
	


	while (gamewindow->isOpen())
	{
		if (!musicservice->isPlaying())
			musicservice->play();
		bt_newGame->setState(bt_newGame->isHover(sf::Mouse::getPosition(*gamewindow->getWindow())));

		gamewindow->add(background->getSprite());
		gamewindow->add(bt_newGame->getcurrentSprite());
		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();
	}

	musicservice->stop();
}