#pragma once

#include "SFML\Graphics.hpp"
#include "Logo.h"
#include "GameWindow.h"
#include "Options.h"

#include <windows.h>

class LogoService
{
	int mode = 0;
	Logo* logo;

	bool autoselectcontrast(double i_pow, double i_seconds);
public:
	void showlogo(GameWindow* i_window, double i_pow, double i_seconds = 0);
	void loadlogo(char* path);
	LogoService();
	virtual ~LogoService();
};

