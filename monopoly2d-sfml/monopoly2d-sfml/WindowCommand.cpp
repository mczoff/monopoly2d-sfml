#include "WindowCommand.h"




WindowCommand::WindowCommand()
{
}

WindowCommand::~WindowCommand()
{
}

void WindowCommand::setwindow(GameWindow* i_gamewindow)
{
	gamewindow = i_gamewindow;
}

GameWindow* WindowCommand::getwindow()
{
	return gamewindow;
}