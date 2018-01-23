#include "GameSelectMenu.h"



GameSelectMenu::GameSelectMenu()
{
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png");

	bt_newgame = new GameButton("src/buttons/snewgame.png", "src/buttons/hnewgame.png", "src/buttons/pnewgame.png");
	bt_continuegame = new GameButton("src/buttons/scontinue.png", "src/buttons/hcontinue.png", "src/buttons/pcontinue.png");
	bt_back = new GameButton("src/buttons/sback.png", "src/buttons/hback.png", "src/buttons/pback.png");
	
	bt_newgame->sethoversound("src/sounds/hbuttons.wav");
	bt_continuegame->sethoversound("src/sounds/hbuttons.wav");
	bt_back->sethoversound("src/sounds/hbuttons.wav");

	gamewindow = GameWindow::getInstance();
	options = Options::getInstance();

	oman = StaticGraphicObject::loadFromFile("src/oman.png");
	oman->setSize(sf::Vector2i(225, 575));
	ogirl = StaticGraphicObject::loadFromFile("src/ogirl.png");
	ogirl->setSize(sf::Vector2i(225, 575));

	gamecreatormenu = new GameCreatorMenu();
	showoptionscommand = new ShowCommand(gamecreatormenu);
}


GameSelectMenu::~GameSelectMenu()
{
	delete oman;
	delete ogirl;
	delete background;
	delete bt_newgame;
	delete bt_continuegame;
	delete bt_back;
}

void GameSelectMenu::show()
{
	while (gamewindow->isOpen())
	{
		ogirl->setPosition(sf::Vector2i(options->getwidth() / 7 - ogirl->getSprite()->getGlobalBounds().width / 2, options->getheight() / 2 - ogirl->getSprite()->getGlobalBounds().height / 2));
		oman->setPosition(sf::Vector2i(options->getwidth() / 1.15 - oman->getSprite()->getGlobalBounds().width / 2, options->getheight() / 2 - oman->getSprite()->getGlobalBounds().height / 2));

		bt_newgame->setlocation(sf::Vector2i(options->getwidth() / 2 - bt_newgame->getcurrentSprite()->getGlobalBounds().width / 2, options->getheight() / 3 - bt_newgame->getcurrentSprite()->getGlobalBounds().height / 2));
		bt_continuegame->setlocation(sf::Vector2i(options->getwidth() / 2 - bt_continuegame->getcurrentSprite()->getGlobalBounds().width / 2, options->getheight() / 2 - bt_continuegame->getcurrentSprite()->getGlobalBounds().height / 2));
		bt_back->setlocation(sf::Vector2i(options->getwidth() / 2 - bt_back->getcurrentSprite()->getGlobalBounds().width / 2, options->getheight() / 1.5 - bt_back->getcurrentSprite()->getGlobalBounds().height / 2));

		bt_newgame->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_continuegame->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_back->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));

		bt_newgame->playsound(bt_newgame->getcurrentstate());
		bt_continuegame->playsound(bt_continuegame->getcurrentstate());
		bt_back->playsound(bt_back->getcurrentstate());

		gamewindow->add(background->getSizebleSprite());
		gamewindow->add(oman->getSprite());
		gamewindow->add(ogirl->getSprite());
		gamewindow->add(bt_newgame->getcurrentSprite());
		gamewindow->add(bt_continuegame->getcurrentSprite());
		gamewindow->add(bt_back->getcurrentSprite());

		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();

		bt_newgame->doisclick(showoptionscommand);
		if (bt_back->isclick())
			break;
	}
}