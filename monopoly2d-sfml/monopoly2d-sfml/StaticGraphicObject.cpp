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

StaticGraphicObject* StaticGraphicObject::loadFromFile(char* i_path)
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
		i_size.x / getSprite()->getLocalBounds().width,
		i_size.y / getSprite()->getLocalBounds().height);
}

void StaticGraphicObject::setlocation(sf::Vector2i i_location)
{
	getSprite()->setPosition(sf::Vector2f(float(i_location.x), float(i_location.y)));
}

sf::Vector2i StaticGraphicObject::getsize()
{
	return sf::Vector2i(int(getSprite()->getGlobalBounds().width), int(getSprite()->getGlobalBounds().height));
}