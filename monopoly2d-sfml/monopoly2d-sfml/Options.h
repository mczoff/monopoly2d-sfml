#pragma once

#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include <vector>

class Options
{
	static Options* instance;

	sf::Uint32 flagStyleWindow = sf::Style::Titlebar | sf::Style::Close;
	//TODO: CHECK CUSTOM OPTIONS 

	char* nameWindow;
	int width;
	int height;

	int musicvolume;
	
	Options();
public:
	static Options* getInstance();

	int getmusicvolume();
	int getwidth();
	int getheight();
	char* getnameWindow();

	void setmusicvolume(int i_volume);
	void setwidth(int inner_width);
	void setheight(int inner_height);
	void setnameWindow(char* inner_name);

	int getStyleFlag();

	void loadDefault();

	
	~Options();
};

