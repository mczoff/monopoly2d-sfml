#include "GameCreatorMenu.h"



GameCreatorMenu::GameCreatorMenu()
{
	
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png");

	bt_back = new GameButton("src/buttons/sback.png", "src/buttons/hback.png", "src/buttons/pback.png");
	bt_back->sethoversound("src/sounds/hbuttons.wav");

	bt_create = new GameButton("src/buttons/sstart.png", "src/buttons/hstart.png", "src/buttons/pstart.png");
	bt_create->sethoversound("src/sounds/hbuttons.wav");

	cntbots = StaticGraphicObject::loadFromFile("src/texts/cntbots.png");
	cntplayers = StaticGraphicObject::loadFromFile("src/texts/cntplayers.png");
	man3 = StaticGraphicObject::loadFromFile("src/man3.png");
	man4 = StaticGraphicObject::loadFromFile("src/man4.png");
	man3->setSize(sf::Vector2i(250, 250));
	man4->setSize(sf::Vector2i(300, 300));

	nc_players = new NumericControl();
	nc_players->setmax(5);
	nc_players->setmin(1);
	nc_players->setvalue(1);
	nc_players->loadfontFromFile("src/fonts/phantom.ttf");

	nc_bots = new NumericControl();
	nc_bots->setmax(4);
	nc_bots->setmin(0);
	nc_bots->setvalue(3);
	nc_bots->loadfontFromFile("src/fonts/phantom.ttf");

	gamewindow = GameWindow::getInstance();
	options = Options::getInstance();
}


GameCreatorMenu::~GameCreatorMenu()
{
	delete man3;
	delete cntplayers;
	delete cntbots;
	delete nc_bots;
	delete bt_back;
	delete bt_create;
}

void GameCreatorMenu::show()
{
	while (gamewindow->isOpen())
	{
		bt_create->setlocation(sf::Vector2i(
			options->getwidth() / 4 - bt_create->getcurrentSprite()->getGlobalBounds().width / 2,
			options->getheight() / 3 - bt_create->getcurrentSprite()->getGlobalBounds().height / 2));
		
		bt_back->setlocation(sf::Vector2i(
			options->getwidth() / 4 - bt_back->getcurrentSprite()->getGlobalBounds().width / 2,
			options->getheight() / 2.25));
		
		cntplayers->setlocation(sf::Vector2i(
			options->getwidth() / 2 - options->getwidth() / 16,
			options->getheight() / 2.5));

		nc_players->setlocation(sf::Vector2i(
			options->getwidth() / 2 + options->getwidth() / 4,
			options->getheight() / 2.5));

		cntbots->setlocation(sf::Vector2i(
			options->getwidth() / 2 - options->getwidth() / 16,
			options->getheight() / 1.4));

		nc_bots->setlocation(sf::Vector2i(
			options->getwidth() / 2 + options->getwidth() / 4,
			options->getheight() / 1.4));

		man3->setlocation(sf::Vector2i(
			options->getwidth() / 6,
			options->getheight() / 1.55));

		man4->setlocation(sf::Vector2i(
			options->getwidth() / 2 + options->getwidth() / 16,
			options->getheight() / 22 ));

		bt_create->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_back->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));

		bt_create->playsound(bt_create->getcurrentstate());
		bt_back->playsound(bt_back->getcurrentstate());

		gamewindow->add(background->getSizebleSprite());
		gamewindow->add(bt_create->getcurrentSprite());
		gamewindow->add(bt_back->getcurrentSprite());
		gamewindow->add(cntbots->getSprite());
		gamewindow->add(cntplayers->getSprite());
		gamewindow->add(man3->getSprite());
		gamewindow->add(man4->getSprite());

		nc_players->add(gamewindow);
		nc_bots->add(gamewindow);

		if (nc_bots->isclick())
			nc_players->setvalue(maxvalueingame - nc_bots->getvalue());

		if (nc_players->isclick())
			nc_bots->setvalue(maxvalueingame - nc_players->getvalue());

		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();

		if (bt_back->isclick())
			break;
	}
}