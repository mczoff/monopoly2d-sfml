#pragma once

#include "SFML\Graphics.hpp"

class GameWindow
{
	sf::RenderWindow* window;

public:

	bool isOpen();
	void procEvents();
	void close();

	GameWindow(int i_width, int i_height, char* i_name);	
	virtual ~GameWindow();
};

