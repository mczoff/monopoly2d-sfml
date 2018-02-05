#pragma once

class IGameCommand
{
public:
	virtual void execute() = 0;

	IGameCommand() {}
	virtual ~IGameCommand() {}
};

