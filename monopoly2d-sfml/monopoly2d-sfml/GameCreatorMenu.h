#pragma once

#include "IShowable.h"
#include "GameButton.h"
#include "SFML\Graphics.hpp"
#include "NumericControl.h"
#include "Background.h"

class GameCreatorMenu : public IShowable
{
	Background* background;

	NumericControl* nc_players;

	Options* options;
	GameWindow* gamewindow;

	GameButton* bt_back;
	GameButton* bt_create;

public:

	void show();

	GameCreatorMenu();
	virtual ~GameCreatorMenu();
};

