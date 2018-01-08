#pragma once

#include "WindowCommand.h"
#include "Options.h"

class ExitCommand : public WindowCommand
{
public:
	void execute();

	ExitCommand();
	virtual ~ExitCommand();
};

