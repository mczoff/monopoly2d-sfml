#pragma once

#include "StaticGraphicObject.h"
#include "Options.h"

class GameComponentBuilder
{
	double boardscope;
	
public:
	Options* options;

	StaticGraphicObject* buildBoard(int spacesize = 0);



	GameComponentBuilder();
	virtual ~GameComponentBuilder();
};

