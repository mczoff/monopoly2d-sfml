#include "Options.h"


Options* Options::instance = 0;

Options::Options()
{
	loadDefault();
}


Options::~Options()
{
}

void Options::loadDefault()
{
	if (flagStyleWindow == sf::Style::Fullscreen)
	{
		std::vector<sf::VideoMode> ss = sf::VideoMode::getFullscreenModes();

		setwidth(ss[0].width);
		setheight(ss[0].height);
	}
	else
	{
		setwidth(1280);
		setheight(720);
	}
	setnameWindow("Monopoly2d");
	setmusicvolume(100);
}

Options* Options::getInstance()
{
	if (instance == 0)
		instance = new Options();
	return instance;
}

int Options::getwidth()
{
	return width;
}

char* Options::getnameWindow()
{
	return nameWindow;
}


int Options::getheight()
{
	return height;
}

int Options::getStyleFlag()
{
	return flagStyleWindow;
}

int Options::getmusicvolume()
{
	return musicvolume;
}

void Options::setwidth(int inner_width)
{
	width = inner_width;
}

void Options::setheight(int inner_height)
{
	height = inner_height;
}

void Options::setnameWindow(char* inner_name)
{
	nameWindow = inner_name;
}

void Options::setmusicvolume(int i_volume)
{
	musicvolume = i_volume;
}