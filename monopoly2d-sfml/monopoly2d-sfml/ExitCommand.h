#pragma once
#include "WindowCommand.h"

class ExitCommand : public WindowCommand
{
public:
	void execute();

	ExitCommand();
	virtual ~ExitCommand();
};

