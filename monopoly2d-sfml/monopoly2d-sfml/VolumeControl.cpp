#include "VolumeControl.h"



VolumeControl::VolumeControl()
{
	bt_down = new GameButton("src/buttons/sdown.png", "src/buttons/hdown.png", "src/buttons/pdown.png");
	bt_up = new GameButton("src/buttons/sup.png", "src/buttons/hup.png", "src/buttons/pup.png");

	bt_down->sethoversound("src/sounds/hbuttons.wav");
	bt_up->sethoversound("src/sounds/hbuttons.wav");
}


VolumeControl::~VolumeControl()
{
}

void VolumeControl::setlocation(sf::Vector2i i_position)
{
	position = i_position;
}

sf::Vector2i VolumeControl::getlocation()
{
	return position;
}

void VolumeControl::add(GameWindow* i_gamewindow)
{
	refreshvolumestate();

	i_gamewindow->add(bt_up->getcurrentSprite());
	i_gamewindow->add(bt_down->getcurrentSprite());
	
	for (int i = 0; i < volumestate.size(); i++)
	{
		volumestate.at(i)->setlocation(sf::Vector2i(position.x + (spacevalue * i) + bt_down->getcurrentSprite()->getGlobalBounds().width, position.y));
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

ClickableObject*  VolumeControl::getbt_down()
{
	return bt_down;
}

ClickableObject*  VolumeControl::getbt_up()
{
	return bt_up;
}

int VolumeControl::getspacevalue()
{
	return spacevalue;
}

void VolumeControl::playbuttonssound()
{
	bt_down->playsound(bt_down->getcurrentstate());
	bt_up->playsound(bt_up->getcurrentstate());
}