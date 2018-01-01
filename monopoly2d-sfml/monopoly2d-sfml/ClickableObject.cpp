#include "ClickableObject.h"



ClickableObject::ClickableObject()
{
	source_image = new sf::Image();;
	source_texture = new sf::Texture();
	source_sprite = new sf::Sprite();

	hover_image = new sf::Image();;
	hover_texture = new sf::Texture();
	hover_sprite = new sf::Sprite();

	pressed_image = new sf::Image();;
	pressed_texture = new sf::Texture();
	pressed_sprite = new sf::Sprite();
}


ClickableObject::~ClickableObject()
{
	delete source_image;
	delete source_texture;
	delete source_sprite;

	delete hover_image;
	delete hover_texture;
	delete hover_sprite;

	delete pressed_image;
	delete pressed_texture;
	delete pressed_sprite;
}

void ClickableObject::loadsource_imageFromFile(char* i_path)
{
	source_image->loadFromFile(i_path);
	source_texture->loadFromImage(*source_image);
	source_sprite->setTexture(*source_texture);
}

void ClickableObject::loadhover_imageFromFile(char* i_path)
{
	hover_image->loadFromFile(i_path);
	hover_texture->loadFromImage(*hover_image);
	hover_sprite->setTexture(*hover_texture);
}

void ClickableObject::loadpressed_imageFromFile(char* i_path)
{
	pressed_image->loadFromFile(i_path);
	pressed_texture->loadFromImage(*pressed_image);
	pressed_sprite->setTexture(*pressed_texture);
}


sf::Sprite* ClickableObject::getsource_sprite()
{
	return source_sprite;
}

sf::Sprite* ClickableObject::gethover_sprite()
{
	return hover_sprite;
}

sf::Sprite* ClickableObject::getpressed_sprite()
{
	return pressed_sprite;
}

int ClickableObject::refreshState(sf::Vector2i i_mouseposition)
{
	
	if (
		   i_mouseposition.x > position.x
		&& i_mouseposition.x < position.x + getcurrentSprite()->getLocalBounds().width
		&& i_mouseposition.y > position.y
		&& i_mouseposition.y < position.y + getcurrentSprite()->getLocalBounds().height)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			return 2;
		return 1;
	}
	return 0;
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
	if (state == StateClickableObject::None)
		return source_sprite;
	if (state == StateClickableObject::Hover)
		return hover_sprite;
	if (state == StateClickableObject::Click)
		return pressed_sprite;
	return NULL;
}

sf::Vector2i ClickableObject::getposition()
{
	return position;
}

void ClickableObject::setposition(sf::Vector2i i_position)
{
	position = i_position;

	source_sprite->setPosition(sf::Vector2f(i_position.x, i_position.y));
	hover_sprite->setPosition(sf::Vector2f(i_position.x, i_position.y));
	pressed_sprite->setPosition(sf::Vector2f(i_position.x, i_position.y));
}