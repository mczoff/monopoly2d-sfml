#include "GameComponentBuilder.h"



GameComponentBuilder::GameComponentBuilder() :
	options(Options::getInstance())
{
}


GameComponentBuilder::~GameComponentBuilder()
{
}

StaticGraphicObject* GameComponentBuilder::buildBoard(int spacesize)
{

	StaticGraphicObject* tmp = StaticGraphicObject::loadFromFile("src/monopoly/board.png");

	tmp->setSize(sf::Vector2i(options->getwidth(), options->getheight()));

	return tmp;
}