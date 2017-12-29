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
	setwidth(1280);
	setheight(780);
	setnameWindow("Monopoly2d");
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