#pragma once

#include "Field.h"
#include "ColorSite.h"
#include "IGameCommand.h"

class Site : public Field
{


	std::string name;
	ColorSite colorsite;

	int c_house;

	IGameCommand* buycommand;
	
public:
	Site();
	virtual ~Site();
};

