#pragma once

#include "ICommand.h"
#include "OptionsMenu.h"

class OpenOptionsCommand : public ICommand
{
public:
	OptionsMenu* optionsmenu;
	void execute();

	OpenOptionsCommand();
	virtual ~OpenOptionsCommand();
};

