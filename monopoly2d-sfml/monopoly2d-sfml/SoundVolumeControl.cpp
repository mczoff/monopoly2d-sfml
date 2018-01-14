#include "SoundVolumeControl.h"



SoundVolumeControl::SoundVolumeControl()
{
}


SoundVolumeControl::~SoundVolumeControl()
{
}

void SoundVolumeControl::refreshvolumestate()
{
	int mid = Options::getInstance()->getsoundvolume() / 10;

	clearState();
	createState(mid);

	getco_down()->setposition(getposition());

	getco_down()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (getco_down()->isclick())
		Options::getInstance()->setsoundvolume(Options::getInstance()->getsoundvolume() - 10);

	getco_up()->setposition(sf::Vector2i(getposition().x + (getspacevalue() * 11) + getco_down()->getcurrentSprite()->getGlobalBounds().width * 0.9, getposition().y));

	getco_up()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (getco_up()->isclick())
		Options::getInstance()->setsoundvolume(Options::getInstance()->getsoundvolume() + 10);
}
