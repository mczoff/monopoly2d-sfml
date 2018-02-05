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
	source = StaticGraphicObject::loadFromFile(i_path);
}

void ClickableObject::loadhover_imageFromFile(char* i_path)
{
	hover = StaticGraphicObject::loadFromFile(i_path);
}

void ClickableObject::loadpressed_imageFromFile(char* i_path)
{
	pressed = StaticGraphicObject::loadFromFile(i_path);
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

void ClickableObject::refreshState()
{
	sf::Vector2i mouseposition = sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow());

	if (!GameWindow::getInstance()->hasFocus())
		return;

	if (
		mouseposition.x > position.x
		&& mouseposition.x < position.x + getcurrentSprite()->getLocalBounds().width
		&& mouseposition.y > position.y
		&& mouseposition.y < position.y + getcurrentSprite()->getLocalBounds().height)
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

void ClickableObject::setposition(sf::Vector2i i_position)
{
	position = i_position;

	source->setlocation(i_position);
	hover->setlocation(i_position);
	pressed->setlocation(i_position);
}

bool ClickableObject::isclick()
{
	bool tmp = false;
	if (getcurrentstate() == StateObject::Hover && laststate == StateObject::Click)
		tmp = true;
	laststate = state;
	return tmp;
}

void ClickableObject::doisclick(ICommand* i_command)
{

	if (getcurrentstate() == StateObject::Hover && laststate == StateObject::Click)
		i_command->execute();
	laststate = state;
}