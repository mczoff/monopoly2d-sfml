#pragma once

#include "ClickableObject.h"

class Field
{
	ClickableObject* co;

public:
	ClickableObject* getco();
	virtual void execute() = 0;

	Field();
	virtual ~Field();
};

