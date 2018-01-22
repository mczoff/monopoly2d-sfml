#include "Options.h"


Options* Options::instance = NULL;

Options::Options()
{
	loadDefault();
}


Options::~Options()
{
}

void Options::loadDefault()
{
	setvideomode(sf::VideoMode::getDesktopMode());
	setnameWindow("Monopoly2d");
	setmusicvolume(100);
	setsoundvolume(100);
}

void Options::saveoptions(char* i_path)
{
	std::ofstream fout;
	fout.open(i_path);

	fout << getmusicvolume() << std::endl;
	fout << getsoundvolume() << std::endl;
	fout << getheight() << std::endl;
	fout << getwidth() << std::endl;
	fout.close();
}

void Options::loadoptions(char* i_path)
{
	//TODO: CHECK ISEXIST()

	std::ifstream fin(i_path);
	if (!fin)
		return;

	fin >> musicvolume;
	fin >> soundvolume;
	fin >> videomode.height;
	fin >> videomode.width;

	fin.close();
}

Options* Options::getInstance()
{
	if (instance == NULL)
		instance = new Options();
	return instance;
}

int Options::getwidth()
{
	return videomode.width;
}

char* Options::getnameWindow()
{
	return nameWindow;
}

bool Options::getismute()
{
	return ismute;
}


int Options::getheight()
{
	return videomode.height;
}

int Options::getStyleFlag()
{
	return flagStyleWindow;
}

int Options::getmusicvolume()
{
	if (ismute)
		return 0;
	return musicvolume;
}

void Options::setwidth(int i_width)
{
	videomode.width = i_width;
}

void Options::setheight(int i_height)
{
	videomode.height = i_height;
}

void Options::setnameWindow(char* inner_name)
{
	nameWindow = inner_name;
}

void Options::setvideomode(sf::VideoMode i_videomode)
{
	videomode = i_videomode;
}

void Options::setmusicvolume(int i_volume)
{
	if (i_volume < 0 || i_volume > 100)
		return;
	musicvolume = i_volume;
}

void Options::setismute(bool i_ismute)
{
	ismute = i_ismute;
}

int Options::getsoundvolume()
{
	if (ismute)
		return 0;
	return soundvolume;
}

void Options::setsoundvolume(int i_volume)
{
	if (i_volume < 0 || i_volume > 100)
		return;
	soundvolume = i_volume;
}