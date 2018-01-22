#pragma once
class IShowable
{
public:
	virtual void show() = 0;

	IShowable() {}
	virtual ~IShowable() {};
};

