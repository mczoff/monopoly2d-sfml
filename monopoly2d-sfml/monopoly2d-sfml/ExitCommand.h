#pragma once

#include "ICommand.h"
#include "GameWindow.h"

class ExitCommand : public ICommand
{
public:
	void execute();

	ExitCommand();
	virtual ~ExitCommand();
};

