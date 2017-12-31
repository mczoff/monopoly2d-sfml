#include "GameMenu.h"



GameMenu::GameMenu(GameWindow* i_gamewindow)
{
	//TODO: PATH TO BACKGROUND IMAGE
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png"); 
	gamewindow = i_gamewindow;
	musicservice = new MusicService();
	options = Options::getInstance();
}


GameMenu::~GameMenu()
{
	delete background;
	delete musicservice;
}

void GameMenu::show()
{
	//
	options->setmusicvolume(10);
	//
	musicservice->openFromFile("src/menu.wav");
	musicservice->setvolume(options->getmusicvolume());
	

	while (gamewindow->isOpen())
	{
		if (!musicservice->isPlaying())
			musicservice->play();

		gamewindow->add(background->getSprite());
		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();
	}

	musicservice->stop();
}