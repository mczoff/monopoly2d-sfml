#include "Logo.h"


Logo::Logo(char* i_path)
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

	contrast = 0;
}


Logo::~Logo()
{
	delete image;
	delete texture;
	delete sprite;
}

Logo* Logo::loadLogoFromFile(char* i_path)
{
	Logo* tmp = new Logo(i_path);
	return tmp;
}

sf::Sprite* Logo::getSprite()
{
	return sprite;
}

void Logo::incContrast(double value)
{
	if (contrast > 255)
		return;
	contrast += value;
}

void Logo::decContrast(double value)
{
	if (contrast < 0)
		return;
	contrast -= value;
}

double Logo::getConsrast()
{
	return contrast;
}

void Logo::update()
{
	sprite->setColor(sf::Color((int)contrast, (int)contrast, (int)contrast, 255));
}