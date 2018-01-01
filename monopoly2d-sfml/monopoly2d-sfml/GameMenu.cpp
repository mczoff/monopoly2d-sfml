#include "GameMenu.h"



GameMenu::GameMenu(GameWindow* i_gamewindow)
{
	//TODO: PATH TO BACKGROUND IMAGE
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png"); 
	gamewindow = i_gamewindow;
	musicservice = new MusicService();
	options = Options::getInstance();
	//TODO: resize button constant
	bt_newGame = new GameButton(sf::Vector2i(50, 100), "src/menu/snewgame.png", "src/menu/hnewgame.png", "src/menu/pnewgame.png");
	bt_options = new GameButton(sf::Vector2i(50, 250), "src/menu/soptions.png", "src/menu/hoptions.png", "src/menu/poptions.png");
	bt_exit = new GameButton(sf::Vector2i(50, 400), "src/menu/sexit.png", "src/menu/hexit.png", "src/menu/pexit.png");
}


GameMenu::~GameMenu()
{
	delete background;
	delete musicservice;
	delete bt_newGame;
	delete bt_options;
	delete bt_exit;
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
		bt_newGame->setState(bt_newGame->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow())));
		bt_options->setState(bt_options->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow())));
		bt_exit->setState(bt_exit->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow())));

		gamewindow->add(background->getSprite());
		gamewindow->add(bt_newGame->getcurrentSprite());
		gamewindow->add(bt_options->getcurrentSprite());
		gamewindow->add(bt_exit->getcurrentSprite());

		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();
	}

	musicservice->stop();
}