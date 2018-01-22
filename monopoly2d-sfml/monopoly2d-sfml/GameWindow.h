#pragma once

#include "SFML\Graphics.hpp"
#include "MusicService.h"
#include "Options.h"
#include <vector>

class GameWindow
{
	static GameWindow* instance;
	sf::RenderWindow* window;
	std::vector<sf::Drawable*> drawable_objects;
	
	GameWindow(int i_width, int i_height, char* i_name, sf::Uint32 i_style);
public:

	bool isOpen();
	void procEvents();
	void close();
	bool hasFocus();
	void draw();
	void render();
	void clear();

	void add(sf::Drawable* i_object);
	sf::RenderWindow* getWindow();

	static GameWindow* getInstance();
	static GameWindow* createInstance(int i_width, int i_height, char* i_name, sf::Uint32 i_style);
	static GameWindow* recreateInstance(int i_width, int i_height, char* i_name, sf::Uint32 i_style);
	virtual ~GameWindow();
};

