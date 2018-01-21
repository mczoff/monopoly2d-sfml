#include "OptionsMenu.h"



OptionsMenu::OptionsMenu()
{
	options = Options::getInstance();
	gamewindow = GameWindow::getInstance();
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png");

	bt_exit = new GameButton(
		"src/menu/sexit.png", "src/menu/hexit.png", "src/menu/pexit.png");

	man = StaticGraphicObject::loadFromFile("src/man.png");
	man->setSize(sf::Vector2i(400, 400));
	

	mvc = new MusicVolumeControl();
	svc = new SoundVolumeControl();
	rc = new ResolutionControl();	
	rc->loadfontFromFile("src/fonts/phantom.ttf");

	crc = new ChangeResolutionCommand();
}


OptionsMenu::~OptionsMenu()
{
	delete man;
	delete background;
	delete bt_exit;
	delete mvc;
	delete svc;
	delete rc;
	delete crc;
}

void OptionsMenu::show()
{
	while (gamewindow->isOpen())
	{
		background->resize();

		man->setPosition(sf::Vector2i(
			options->getwidth() / 4 - man->getSprite()->getGlobalBounds().width / 2,
			options->getheight() / 2 - man->getSprite()->getGlobalBounds().height / 2));

		mvc->setlocation(sf::Vector2i(
			options->getwidth() / 2 + options->getwidth() / 20,
			options->getheight() / 2 + options->getheight() / 22));

		svc->setlocation(sf::Vector2i(
			options->getwidth() / 2 + options->getwidth() / 20,
			options->getheight() / 2 - options->getheight() / 8));

		rc->setlocation(sf::Vector2i(
			options->getwidth() / 2 + options->getwidth() / 20,
			options->getheight() / 2 - options->getheight() / 3.5));

		bt_exit->setlocation(sf::Vector2i(
			options->getwidth() / 4 + options->getwidth() / 2 - bt_exit->getcurrentSprite()->getGlobalBounds().width / 2,
			options->getheight() / 1.25 - bt_exit->getcurrentSprite()->getGlobalBounds().height / 2));

		bt_exit->refreshState(sf::Mouse::getPosition(*gamewindow->getWindow()));
		bt_exit->playSound(bt_exit->getcurrentstate());
		
		gamewindow->add(background->getSizebleSprite());
		gamewindow->add(man->getSprite());
		gamewindow->add(bt_exit->getcurrentSprite());

		rc->add(gamewindow);
		mvc->add(gamewindow);
		svc->add(gamewindow);
	
		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();
	

		if (bt_exit->isclick())
		{
			Options::getInstance()->setvideomode(rc->getvideomode());
			crc->execute();
			break;
		}
	}
}