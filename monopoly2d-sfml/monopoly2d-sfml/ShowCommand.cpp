#include "ShowCommand.h"



ShowCommand::ShowCommand(IShowable* i_showobject) 
	: showobject(i_showobject)
{
}


ShowCommand::~ShowCommand()
{
}

void ShowCommand::execute()
{
	showobject->show();
}