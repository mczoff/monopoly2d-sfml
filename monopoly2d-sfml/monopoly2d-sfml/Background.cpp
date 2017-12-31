#include "Background.h"



Background::Background(char* i_path)
{
	Options* options = Options::getInstance();

	image = new sf::Image();
	texture = new sf::Texture();
	sprite = new sf::Sprite();

	image->loadFromFile(i_path);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);

	sprite->setScale(
		options->getwidth() / sprite->getLocalBounds().width,
		options->getheight() / sprite->getLocalBounds().height);
}

sf::Sprite* Background::getSprite()
{
	return sprite;
}

Background::~Background()
{
	delete image;
	delete texture;
	delete sprite;
}

Background* Background::loadBackgroundFromFile(char* i_path)
{
	Background* tmp = new Background(i_path);
	return tmp;
}