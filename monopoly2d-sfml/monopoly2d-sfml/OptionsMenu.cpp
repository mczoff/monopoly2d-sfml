#include "OptionsMenu.h"



OptionsMenu::OptionsMenu()
{
	options = Options::getInstance();
	gamewindow = GameWindow::getInstance();
	background = Background::loadBackgroundFromFile("src/backgroundmenu.jpg");

	bt_exit = new GameButton(
		"src/menu/sexit.png", "src/menu/hexit.png", "src/menu/pexit.png");
	bt_exit->setlocation(sf::Vector2i(
		options->getwidth() / 4 + options->getwidth() / 2 - bt_exit->getcurrentSprite()->getGlobalBounds().width / 2,
		options->getheight() / 4 + bt_exit->getcurrentSprite()->getGlobalBounds().height / 4 + 300));
	
	man = StaticGraphicObject::loadFromFile("src/man.png");
	man->setSize(sf::Vector2i(400, 400));
	man->setPosition(sf::Vector2i(
		options->getwidth() / 4 - man->getSprite()->getGlobalBounds().width / 2,
		options->getheight() / 2 - man->getSprite()->getGlobalBounds().height / 2));

	mvc = new MusicVolumeControl();
	mvc->setlocation(sf::Vector2i(
		options->getwidth() / 5 + options->getwidth() / 2 - bt_exit->getcurrentSprite()->getGlobalBounds().width / 2,
		options->getheight() / 4 + bt_exit->getcurrentSprite()->getGlobalBounds().height / 4));
}


OptionsMenu::~OptionsMenu()
{
	delete man;
	delete background;
	delete bt_exit;
}

void OptionsMenu::show()
{
	while (gamewindow->isOpen())
	{

		bt_exit->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_exit->playSound(bt_exit->getcurrentstate());

		
		gamewindow->add(background->getSprite());
		gamewindow->add(man->getSprite());
		gamewindow->add(bt_exit->getcurrentSprite());
		mvc->add(gamewindow);
		
		if (bt_exit->getcurrentstate() == StateObject::Click)
			break;

		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();
	}

}