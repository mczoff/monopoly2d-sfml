#include "MusicVolumeControl.h"

MusicVolumeControl::MusicVolumeControl()
{
	options = Options::getInstance();
	co_down = new ClickableObject();

	co_down->loadsource_imageFromFile("src/options/click_volume_down.png");
	co_down->loadhover_imageFromFile("src/options/click_volume_down.png");
	co_down->loadpressed_imageFromFile("src/options/click_volume_down.png");
	
	co_up = new ClickableObject();

	co_up->loadsource_imageFromFile("src/options/click_volume_up.png");
	co_up->loadhover_imageFromFile("src/options/click_volume_up.png");
	co_up->loadpressed_imageFromFile("src/options/click_volume_up.png");

}

MusicVolumeControl::~MusicVolumeControl()
{

}

void MusicVolumeControl::refreshvolumestate()
{
	for (int i = 0; i < volumestate.size(); i++)
		volumestate.at(i)->~StaticGraphicObject();
	volumestate.clear();

	
	int mid = options->getmusicvolume() / 10;
	
	for (int i = 0; i < 10; i++)
	{
		if (i < mid)
			volumestate.push_back(StaticGraphicObject::loadFromFile("src/options/onstepvolume.png"));
		else
			volumestate.push_back(StaticGraphicObject::loadFromFile("src/options/offstepvolume.png"));
	}

	co_down->setPosition(position);

	co_down->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (co_down->isclick())
		options->setmusicvolume(options->getmusicvolume() - 10);

	co_up->setPosition(sf::Vector2i(position.x + (spacevalue * 11) + co_down->getcurrentSprite()->getGlobalBounds().width * 0.9, position.y));

	co_up->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (co_up->isclick())
		options->setmusicvolume(options->getmusicvolume() + 10);
}

void MusicVolumeControl::setlocation(sf::Vector2i i_position)
{
	position = i_position;
}

sf::Vector2i MusicVolumeControl::getlocation()
{
	return position;
}

void MusicVolumeControl::add(GameWindow* i_gamewindow)
{
	refreshvolumestate();


	i_gamewindow->add(co_up->getcurrentSprite());
	i_gamewindow->add(co_down->getcurrentSprite());
	for (int i = 0; i < volumestate.size(); i++)
	{
		volumestate.at(i)->setPosition(sf::Vector2i(position.x + (spacevalue * i) + co_down->getcurrentSprite()->getGlobalBounds().width, position.y));
		i_gamewindow->add(volumestate.at(i)->getSprite());
	}

}