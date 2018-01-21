#include "GameMenu.h"

#include <functional>

GameMenu::GameMenu()
{
	//TODO: Refresh Button click
	//TODO: PATH TO BACKGROUND IMAGE
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png"); 
	gamewindow = GameWindow::getInstance();
	options = Options::getInstance();

	//TODO: resize button constant
	bt_newGame = new GameButton("src/menu/snewgame.png", "src/menu/hnewgame.png", "src/menu/pnewgame.png");
	bt_options = new GameButton("src/menu/soptions.png", "src/menu/hoptions.png", "src/menu/poptions.png");
	bt_exit = new GameButton("src/menu/sexit.png", "src/menu/hexit.png", "src/menu/pexit.png");

	bt_newGame->sethoversound("src/sounds/cmenu.wav");
	bt_options->sethoversound("src/sounds/cmenu.wav");
	bt_exit->sethoversound("src/sounds/cmenu.wav");

	
	man = StaticGraphicObject::loadFromFile("src/man.png");
	man->setSize(sf::Vector2i(400, 400));


	exitcommand = new ExitCommand();
	openoptionscommand = new OpenOptionsCommand();

	musicservice = MusicService::getInstance();
}


GameMenu::~GameMenu()
{
	delete background;
	delete bt_newGame;
	delete bt_options;
	delete bt_exit;
	delete exitcommand;
	delete openoptionscommand;
}

void GameMenu::show()
{
	musicservice->openFromFile("src/menu/fon.wav");
	musicservice->setvolume(options->getmusicvolume());
	musicservice->setloop(true);
	musicservice->play();

	while (gamewindow->isOpen())
	{
		bt_newGame->setlocation(sf::Vector2i(options->getwidth() / 12, options->getheight() / 3 - bt_newGame->getcurrentSprite()->getGlobalBounds().height / 2));
		bt_options->setlocation(sf::Vector2i(options->getwidth() / 12, options->getheight() / 2 - bt_options->getcurrentSprite()->getGlobalBounds().height / 2));
		bt_exit->setlocation(sf::Vector2i(options->getwidth() / 12, options->getheight() / 1.5 - bt_exit->getcurrentSprite()->getGlobalBounds().height / 2));

		man->setPosition(sf::Vector2i(
			options->getwidth() / 4 + options->getwidth() / 2 - man->getSprite()->getGlobalBounds().width / 2,
			options->getheight() / 2 - man->getSprite()->getGlobalBounds().height / 2));

		//MAYBE: DO EASIER
		if (musicservice->getvolume() == 0 && options->getmusicvolume() != 0)
			musicservice->play();
		musicservice->setvolume(options->getmusicvolume());
		if (musicservice->getvolume() == 0)
			musicservice->stop();

		bt_newGame->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_options->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_exit->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));

		bt_newGame->playSound(bt_newGame->getcurrentstate());
		bt_options->playSound(bt_options->getcurrentstate());
		bt_exit->playSound(bt_exit->getcurrentstate());

		gamewindow->add(background->getSizebleSprite());
		gamewindow->add(man->getSprite());
		gamewindow->add(bt_newGame->getcurrentSprite());
		gamewindow->add(bt_options->getcurrentSprite());
		gamewindow->add(bt_exit->getcurrentSprite());

		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();

		bt_exit->doisclick(exitcommand);
		bt_options->doisclick(openoptionscommand);

		background->resize();
	}

	musicservice->stop();
}