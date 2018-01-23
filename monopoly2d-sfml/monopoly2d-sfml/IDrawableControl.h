#pragma once

#include "GameWindow.h"

class IDrawableControl
{
public:

	virtual void add(GameWindow* i_gamewindow) = 0;

	IDrawableControl() {};
	virtual ~IDrawableControl() {};
};
