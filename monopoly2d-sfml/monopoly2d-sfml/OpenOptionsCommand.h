#pragma once

#include "WindowCommand.h"
#include "OptionsMenu.h"

class OpenOptionsCommand : public WindowCommand 
{
public:
	OptionsMenu* optionsmenu;
	void execute();

	OpenOptionsCommand();
	virtual ~OpenOptionsCommand();
};

