#include "ExitCommand.h"



ExitCommand::ExitCommand()
{
}


ExitCommand::~ExitCommand()
{
}

void ExitCommand::execute()
{
	getwindow()->close();
	Options::getInstance()->saveoptions("config.ini");
}