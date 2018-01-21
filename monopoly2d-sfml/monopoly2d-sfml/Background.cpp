#include "Background.h"



Background::Background(char* i_path)
{
	object = StaticGraphicObject::loadFromFile(i_path);
	resize();
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

sf::Sprite* Background::getSizebleSprite()
{
	return getobject()->getSprite();
}

void Background::resize()
{
	Options* options = Options::getInstance();
	if (object->getSprite()->getGlobalBounds().width == options->getwidth() && object->getSprite()->getGlobalBounds().height == options->getheight())
		return;
	object->setSize(sf::Vector2i(options->getwidth(), options->getheight()));
}