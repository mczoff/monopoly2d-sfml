#pragma once

#include "SFML\Graphics.hpp"

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
	void update();
	void decContrast(double value);

};

