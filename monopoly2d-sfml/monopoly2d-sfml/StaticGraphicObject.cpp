#include "StaticGraphicObject.h"



StaticGraphicObject::StaticGraphicObject(char* i_path)
{
	image = new sf::Image();
	texture = new sf::Texture();
	sprite = new sf::Sprite();

	image->loadFromFile(i_path);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);
}


StaticGraphicObject::~StaticGraphicObject()
{
	delete image;
	delete texture;
	delete sprite;
}

StaticGraphicObject* StaticGraphicObject::loadBackgroundFromFile(char* i_path)
{
	return new StaticGraphicObject(i_path);
}

sf::Sprite* StaticGraphicObject::getSprite()
{
	return sprite;
}

void StaticGraphicObject::setSize(sf::Vector2i i_size)
{
	getSprite()->setScale(
		i_size.x / getSprite()->getGlobalBounds().width,
		i_size.y / getSprite()->getGlobalBounds().height);
}

void StaticGraphicObject::setLocation(sf::Vector2i i_location)
{
	getSprite()->setPosition(sf::Vector2f(i_location.x,i_location.y));
}