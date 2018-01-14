#pragma once

#include "SFML\Graphics.hpp"

#include "StateObject.h"
#include "StaticGraphicObject.h"
#include "ICommand.h"
#include "GameWindow.h"

class ClickableObject
{
	int laststate;
	int state;

	sf::Vector2i position;

	StaticGraphicObject* source;
	StaticGraphicObject* hover;
	StaticGraphicObject* pressed;

	sf::Sprite* getsource_sprite();
	sf::Sprite* gethover_sprite();
	sf::Sprite* getpressed_sprite();

public:
	void doisclick(ICommand* i_command);
	bool isclick();

	void loadsource_imageFromFile(char* i_path);
	void loadhover_imageFromFile(char* i_path);
	void loadpressed_imageFromFile(char* i_path);

	void refreshState(sf::Vector2i position);
	void setState(int i_state);
	void setposition(sf::Vector2i i_position);

	int getcurrentstate();
	sf::Sprite* getcurrentSprite();
	sf::Vector2i getposition();

	ClickableObject();
	virtual ~ClickableObject();
};
