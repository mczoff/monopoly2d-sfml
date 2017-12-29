#include "GameWindow.h"



GameWindow::GameWindow(int i_width, int i_height, char* i_name)
{
	window = new sf::RenderWindow(sf::VideoMode(i_width, i_height), i_name);
}


GameWindow::~GameWindow()
{
}

bool GameWindow::isOpen()
{
	return window->isOpen();
}
void GameWindow::procEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

}
void GameWindow::close()
{
	window->close();
}