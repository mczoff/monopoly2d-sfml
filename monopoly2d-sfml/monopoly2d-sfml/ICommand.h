#pragma once
class ICommand
{
public:
	virtual void execute() = 0;

	ICommand() {}
	virtual ~ICommand() {}
};

