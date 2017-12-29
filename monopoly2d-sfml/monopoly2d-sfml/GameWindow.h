#pragma once

#include "SFML\Graphics.hpp"

#include <vector>

class GameWindow
{
	sf::RenderWindow* window;
	
	std::vector<sf::Drawable*> drawable_objects;
	
public:

	bool isOpen();
	void procEvents();
	void close();

	void draw();
	void render();
	void clear();

	void add(sf::Drawable* i_object);

	GameWindow(int i_width, int i_height, char* i_name);	
	virtual ~GameWindow();
};

