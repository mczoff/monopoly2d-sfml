#include "ExitCommand.h"



ExitCommand::ExitCommand()
{
}


ExitCommand::~ExitCommand()
{
}

void ExitCommand::execute()
{
	GameWindow::getInstance()->getWindow()->close();
}