#include "GameCreatorMenu.h"



GameCreatorMenu::GameCreatorMenu()
{
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png");

	bt_back = new GameButton("src/buttons/sback.png", "src/buttons/hback.png", "src/buttons/pback.png");
	bt_back->sethoversound("src/sounds/hbuttons.wav");
	bt_create = new GameButton("src/buttons/sstart.png", "src/buttons/hstart.png", "src/buttons/pstart.png");
	bt_create->sethoversound("src/sounds/hbuttons.wav");
	nc_players = new NumericControl();

	nc_players->setlocation(sf::Vector2i(0, 0));
	nc_players->setmax(4);
	nc_players->setmin(0);
	nc_players->setvalue(0);
	nc_players->loadfontFromFile("src/fonts/phantom.ttf");

	gamewindow = GameWindow::getInstance();
	options = Options::getInstance();
}


GameCreatorMenu::~GameCreatorMenu()
{
	delete bt_back;
	delete bt_create;
}

void GameCreatorMenu::show()
{
	while (gamewindow->isOpen())
	{

		bt_create->setlocation(sf::Vector2i(options->getwidth() / 2 - bt_create->getcurrentSprite()->getGlobalBounds().width / 2, options->getheight() / 2 - bt_create->getcurrentSprite()->getGlobalBounds().height / 2));
		bt_back->setlocation(sf::Vector2i(options->getwidth() / 2 - bt_back->getcurrentSprite()->getGlobalBounds().width / 2, options->getheight() / 1.5 - bt_back->getcurrentSprite()->getGlobalBounds().height / 2));

		bt_create->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_back->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));

		bt_create->playsound(bt_create->getcurrentstate());
		bt_back->playsound(bt_back->getcurrentstate());

		gamewindow->add(background->getSizebleSprite());
		gamewindow->add(bt_create->getcurrentSprite());
		gamewindow->add(bt_back->getcurrentSprite());
		nc_players->add(gamewindow);

		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();


		if (bt_back->isclick())
			break;
	}
}