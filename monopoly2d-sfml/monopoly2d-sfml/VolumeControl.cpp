#include "VolumeControl.h"



VolumeControl::VolumeControl()
{
	co_down = new ClickableObject();

	co_down->loadsource_imageFromFile("src/options/click_volume_down.png");
	co_down->loadhover_imageFromFile("src/options/hover_volume_down.png");
	co_down->loadpressed_imageFromFile("src/options/pressed_volume_down.png");

	co_up = new ClickableObject();

	co_up->loadsource_imageFromFile("src/options/click_volume_up.png");
	co_up->loadhover_imageFromFile("src/options/hover_volume_up.png");
	co_up->loadpressed_imageFromFile("src/options/pressed_volume_up.png");
}


VolumeControl::~VolumeControl()
{
}

void VolumeControl::setlocation(sf::Vector2i i_position)
{
	position = i_position;
}

sf::Vector2i VolumeControl::getposition()
{
	return position;
}

void VolumeControl::add(GameWindow* i_gamewindow)
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

void VolumeControl::clearState()
{
	for (int i = 0; i < volumestate.size(); i++)
		volumestate.at(i)->~StaticGraphicObject();
	volumestate.clear();
}
void VolumeControl::createState(int mid)
{
	const int countbars = 10;

	for (int i = 0; i < countbars; i++)
	{
		if (i < mid)
			volumestate.push_back(StaticGraphicObject::loadFromFile("src/options/onstepvolume.png"));
		else
			volumestate.push_back(StaticGraphicObject::loadFromFile("src/options/offstepvolume.png"));
	}
}

ClickableObject*  VolumeControl::getco_down()
{
	return co_down;
}

ClickableObject*  VolumeControl::getco_up()
{
	return co_up;
}

int VolumeControl::getspacevalue()
{
	return spacevalue;
}