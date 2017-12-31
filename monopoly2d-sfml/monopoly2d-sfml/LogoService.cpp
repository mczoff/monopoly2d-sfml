#include "LogoService.h"



LogoService::LogoService()
{
}


LogoService::~LogoService()
{
}


void LogoService::showlogo(GameWindow* i_window, double i_pow, double i_seconds)
{
	while (i_window->isOpen())
	{
		if (!autoselectcontrast(i_pow, i_seconds))
			return;

		logo->update();
		i_window->add(logo->getSprite());	
		i_window->draw();
		i_window->procEvents();
		i_window->render();
		i_window->clear();
	}
}

void LogoService::loadlogo(char* i_path)
{
	logo = Logo::loadLogoFromFile(i_path);
	mode = 0;
}

bool LogoService::autoselectcontrast(double i_pow, double i_seconds)
{
	if (mode == 0)
	{
		logo->incContrast(i_pow);

		if ((int)logo->getConsrast() == 255)
		{
			mode = 1;
			sf::sleep(sf::seconds(i_seconds));
		}
	}
	if (mode == 1)
	{
		logo->decContrast(i_pow);
		if ((int)logo->getConsrast() == 0)
			return false;
	}
	return true;
}