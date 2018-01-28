#pragma once

#include "GameButton.h"
#include "StaticGraphicObject.h"
#include "SFML\Graphics.hpp"
#include "GameWindow.h"
#include "IDrawableControl.h"

class NumericControl : public IDrawableControl
{
	bool flagclick;

	int value;

	int max;
	int min;

	sf::Text* text;
	sf::Font font;

	sf::Vector2i position;

	GameButton* bt_down;
	GameButton* bt_up;

public:
	bool isclick();
	sf::Font getfont();
	void setlocation(sf::Vector2i i_position);
	sf::Vector2i getlocation();

	ClickableObject* getco_down();
	ClickableObject* getco_up();

	void playbuttonssound();
	void loadfontFromFile(char* i_path);
	void settextposition(sf::Vector2i i_position);

	void setmin(int i_min);
	void setmax(int i_max);

	int getvalue();
	void setvalue(int i_value);

	void incvalue(int i_value = 1);
	void decvalue(int i_value = 1);

	void add(GameWindow* i_gamewindow);

	void refreshtext(const sf::Color i_color);

	NumericControl();
	virtual ~NumericControl();
};

