#include "Background.h"



Background::Background(char* i_path)
{
	Options* options = Options::getInstance();
	object = StaticGraphicObject::loadFromFile(i_path);
	object->setSize(sf::Vector2i(options->getwidth(), options->getheight()));
}

StaticGraphicObject* Background::getobject()
{
	return object;
}

Background::~Background()
{
	
}

Background* Background::loadBackgroundFromFile(char* i_path)
{
	Background* tmp = new Background(i_path);
	return tmp;
}

sf::Sprite* Background::getSprite()
{
	return getobject()->getSprite();
}