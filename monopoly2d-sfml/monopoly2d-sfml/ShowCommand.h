#pragma once

#include "ICommand.h"
#include "IShowable.h"

class ShowCommand : public ICommand
{
	IShowable* showobject;
public:
	void execute();

	ShowCommand(IShowable* i_showobject);
	virtual ~ShowCommand();
};

