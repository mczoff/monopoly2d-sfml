#pragma once

#include "SFML\Graphics.hpp"
#include "Logo.h"
#include "GameWindow.h"

class LogoService
{
	sf::Mutex mutex;
	sf::Thread thread;
	sf::Clock clock;

	GameWindow* window;
	Logo* logo;
	double seconds;
	double pow;

	void showinglogo();
public:
	void showlogo();
	void loadlogo(char* path);
	void setparams(double i_seconds, GameWindow* i_window, double i_pow);
	LogoService();
	virtual ~LogoService();
};

