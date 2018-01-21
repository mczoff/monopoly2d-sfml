#pragma once

#include "ICommand.h"
#include "GameWindow.h"
#include "Options.h"

class ChangeResolutionCommand : public ICommand
{
public:
	void execute();

	ChangeResolutionCommand();
	~ChangeResolutionCommand();
};

