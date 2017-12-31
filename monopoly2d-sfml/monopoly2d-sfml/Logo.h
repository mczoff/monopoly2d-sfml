#pragma once

#include "SFML\Graphics.hpp"
#include "Options.h"

class Logo
{
	sf::Image* image;
	sf::Texture* texture;
	sf::Sprite* sprite;

	Logo(char* i_path);

	double contrast;
public:
	sf::Sprite* getSprite();

	static Logo* loadLogoFromFile(char* path);

	virtual ~Logo();


	void incContrast(double value);
	double getConsrast();
	void decContrast(double value);
	void update();

};

