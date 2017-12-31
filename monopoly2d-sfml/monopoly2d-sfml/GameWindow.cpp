#include "GameWindow.h"



GameWindow::GameWindow(int i_width, int i_height, char* i_name, int i_style)
{
	window = new sf::RenderWindow(sf::VideoMode(i_width, i_height), i_name, sf::Uint32(i_style));
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

void GameWindow::draw()
{
	for (int i = 0; i < drawable_objects.size(); i++)
	{
		window->draw(*drawable_objects.at(i));
	}
}

void GameWindow::render()
{
	window->display();
}

void GameWindow::clear()
{
	drawable_objects.clear();
}

void GameWindow::add(sf::Drawable* i_object)
{
	drawable_objects.push_back(i_object);
}

sf::RenderWindow* GameWindow::getWindow()
{
	return window;
}