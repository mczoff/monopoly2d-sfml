#include "OpenOptionsCommand.h"



OpenOptionsCommand::OpenOptionsCommand()
{
	optionsmenu = new OptionsMenu();
}


OpenOptionsCommand::~OpenOptionsCommand()
{
	delete optionsmenu;
}

void OpenOptionsCommand::execute()
{
	optionsmenu->show();
}