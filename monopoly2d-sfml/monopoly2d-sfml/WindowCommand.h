#pragma once

#include "ICommand.h"
#include "GameWindow.h"

class WindowCommand 
	: public ICommand
{
	GameWindow* gamewindow;

public:

	void setwindow(GameWindow* i_gamewindow);
	GameWindow* getwindow();

	WindowCommand();
	virtual ~WindowCommand();
};

