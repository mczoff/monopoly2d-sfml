#include "Logo.h"

//"logo/rhorvald.jpg"

Logo::Logo(char* i_path)
{
	image = new sf::Image();
	texture = new sf::Texture();
	sprite = new sf::Sprite();

	image->loadFromFile(i_path);
	texture->loadFromImage(*image);
	sprite->setTexture(*texture);

	contrast = 255;
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
	if (contrast > 254)
		return;
	contrast += value;
}

void Logo::update()
{
	sprite->setColor(sf::Color((int)contrast, (int)contrast, (int)contrast, 255));
}

void Logo::decContrast(double value)
{
	if (contrast < 1)
		return;
	contrast -= value;
}
