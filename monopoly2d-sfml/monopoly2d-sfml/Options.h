#pragma once

#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"

#include <fstream>

class Options
{
	static Options* instance;

	sf::Uint32 flagStyleWindow = sf::Style::Titlebar | sf::Style::Close;

	char* nameWindow;
	int width;
	int height;

	int musicvolume;
	int soundvolume;
	
	Options();
public:
	static Options* getInstance();

	int getmusicvolume();
	int getsoundvolume();
	int getwidth();
	int getheight();
	char* getnameWindow();

	void setsoundvolume(int i_volume);
	void setmusicvolume(int i_volume);
	void setwidth(int inner_width);
	void setheight(int inner_height);
	void setnameWindow(char* inner_name);

	int getStyleFlag();

	void loadDefault();
	void saveoptions(char* i_path);
	void loadoptions(char* i_path);
	
	~Options();
};

