#pragma once

#include "Background.h"
#include "StaticGraphicObject.h"
#include "MusicService.h"
#include "GameButton.h"
#include "GameWindow.h"
#include "WindowCommand.h"

class OptionsMenu
{
	Options* options;
	GameWindow* gamewindow;
	StaticGraphicObject* man;
	Background* background;
	GameButton* bt_exit;
	MusicService* musicservice;

public:

	void show();

	OptionsMenu();
	virtual ~OptionsMenu();
};

