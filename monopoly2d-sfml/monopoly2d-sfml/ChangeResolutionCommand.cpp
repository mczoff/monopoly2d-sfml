#include "ChangeResolutionCommand.h"



ChangeResolutionCommand::ChangeResolutionCommand()
{
}


ChangeResolutionCommand::~ChangeResolutionCommand()
{
}

void ChangeResolutionCommand::execute()
{
	Options* options = Options::getInstance();

	GameWindow::recreateInstance(
		options->getwidth(),
		options->getheight(),
		options->getnameWindow(),
		options->getStyleFlag());


}