#include "GameMenu.h"

#include <functional>

GameMenu::GameMenu()
{
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png"); 
	gamewindow = GameWindow::getInstance();
	options = Options::getInstance();

	bt_game = new GameButton("src/buttons/sgame.png", "src/buttons/hgame.png", "src/buttons/pgame.png");
	bt_options = new GameButton("src/buttons/soptions.png", "src/buttons/hoptions.png", "src/buttons/poptions.png");
	bt_exit = new GameButton("src/buttons/sexit.png", "src/buttons/hexit.png", "src/buttons/pexit.png");

	bt_game->sethoversound("src/sounds/hbuttons.wav");
	bt_options->sethoversound("src/sounds/hbuttons.wav");
	bt_exit->sethoversound("src/sounds/hbuttons.wav");
	
	man = StaticGraphicObject::loadFromFile("src/man.png");
	man->setSize(sf::Vector2i(400, 400));

	optionsmenu = new OptionsMenu();
	gameselectmenu = new GameSelectMenu();

	exitcommand = new ExitCommand();
	showoptionscommand = new ShowCommand(optionsmenu);
	showgamecreatormenucommand = new ShowCommand(gameselectmenu);

	musicservice = MusicService::getInstance();
}


GameMenu::~GameMenu()
{
	delete background;
	delete bt_game;
	delete bt_options;
	delete bt_exit;
	delete exitcommand;
	delete exitcommand;
	delete showoptionscommand;
	delete showgamecreatormenucommand;
}

void GameMenu::show()
{
	musicservice->openFromFile("src/menu/fon.wav");
	musicservice->setvolume(options->getmusicvolume());
	musicservice->setloop(true);
	musicservice->play();

	while (gamewindow->isOpen())
	{
		bt_game->setlocation(sf::Vector2i(options->getwidth() / 12, options->getheight() / 3 - bt_game->getcurrentSprite()->getGlobalBounds().height / 2));
		bt_options->setlocation(sf::Vector2i(options->getwidth() / 12, options->getheight() / 2 - bt_options->getcurrentSprite()->getGlobalBounds().height / 2));
		bt_exit->setlocation(sf::Vector2i(options->getwidth() / 12, options->getheight() / 1.5 - bt_exit->getcurrentSprite()->getGlobalBounds().height / 2));

		man->setlocation(sf::Vector2i(
			options->getwidth() / 4 + options->getwidth() / 2 - man->getSprite()->getGlobalBounds().width / 4,
			options->getheight() / 2 - man->getSprite()->getGlobalBounds().height / 2));

		//MAYBE: DO EASIER
		if (musicservice->getvolume() == 0 && options->getmusicvolume() != 0)
			musicservice->play();
		musicservice->setvolume(options->getmusicvolume());
		if (musicservice->getvolume() == 0)
			musicservice->stop();

		bt_game->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_options->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_exit->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));

		bt_game->playsound(bt_game->getcurrentstate());
		bt_options->playsound(bt_options->getcurrentstate());
		bt_exit->playsound(bt_exit->getcurrentstate());

		gamewindow->add(background->getSizebleSprite());
		gamewindow->add(man->getSprite());
		gamewindow->add(bt_game->getcurrentSprite());
		gamewindow->add(bt_options->getcurrentSprite());
		gamewindow->add(bt_exit->getcurrentSprite());

		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();

		bt_exit->doisclick(exitcommand);
		bt_options->doisclick(showoptionscommand);
		bt_game->doisclick(showgamecreatormenucommand);
	}

	musicservice->stop();
}