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

	getbt_down()->setposition(getlocation());

	getbt_down()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (getbt_down()->isclick())
		Options::getInstance()->setsoundvolume(Options::getInstance()->getsoundvolume() - 10);

	getbt_up()->setposition(sf::Vector2i(getlocation().x + (getspacevalue() * 11) + getbt_down()->getcurrentSprite()->getGlobalBounds().width * 0.9, getlocation().y));

	getbt_up()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (getbt_up()->isclick())
		Options::getInstance()->setsoundvolume(Options::getInstance()->getsoundvolume() + 10);
}
