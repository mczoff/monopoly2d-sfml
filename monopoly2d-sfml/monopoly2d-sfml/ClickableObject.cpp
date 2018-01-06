#include "ClickableObject.h"



ClickableObject::ClickableObject()
{

}


ClickableObject::~ClickableObject()
{
	delete source;
	delete hover;
	delete pressed;
}

void ClickableObject::loadsource_imageFromFile(char* i_path)
{
	source = StaticGraphicObject::loadBackgroundFromFile(i_path);
}

void ClickableObject::loadhover_imageFromFile(char* i_path)
{
	hover = StaticGraphicObject::loadBackgroundFromFile(i_path);
}

void ClickableObject::loadpressed_imageFromFile(char* i_path)
{
	pressed = StaticGraphicObject::loadBackgroundFromFile(i_path);
}


sf::Sprite* ClickableObject::getsource_sprite()
{
	return source->getSprite();
}

sf::Sprite* ClickableObject::gethover_sprite()
{
	return  hover->getSprite();
}

sf::Sprite* ClickableObject::getpressed_sprite()
{
	return pressed->getSprite();
}

void ClickableObject::refreshState(sf::Vector2i i_mouseposition)
{
	
	if (
		   i_mouseposition.x > position.x
		&& i_mouseposition.x < position.x + getcurrentSprite()->getLocalBounds().width
		&& i_mouseposition.y > position.y
		&& i_mouseposition.y < position.y + getcurrentSprite()->getLocalBounds().height)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			setState(2);
			return;
		}
		setState(1);
		return;
	}
	setState(0);
	return;
}

void ClickableObject::setState(int i_state)
{
	state = i_state;
}

int ClickableObject::getcurrentstate()
{
	return state;
}

sf::Sprite* ClickableObject::getcurrentSprite()
{
	if (state == StateObject::None)
		return getsource_sprite();
	if (state == StateObject::Hover)
		return gethover_sprite();
	if (state == StateObject::Click)
		return getpressed_sprite();
	return NULL;
}

sf::Vector2i ClickableObject::getposition()
{
	return position;
}

void ClickableObject::setLocation(sf::Vector2i i_position)
{
	position = i_position;

	source->setLocation(i_position);
	hover->setLocation(i_position);
	pressed->setLocation(i_position);
}