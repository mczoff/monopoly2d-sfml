#pragma once

#include "Background.h"
#include "StaticGraphicObject.h"
#include "MusicService.h"
#include "GameButton.h"
#include "GameWindow.h"
#include "WindowCommand.h"
#include "MusicVolumeControl.h"

class OptionsMenu
{
	Options* options;
	GameWindow* gamewindow;
	StaticGraphicObject* man;
	Background* background;
	GameButton* bt_exit;
	MusicService* musicservice;
	MusicVolumeControl* mvc;

public:

	void show();

	OptionsMenu();
	virtual ~OptionsMenu();
};

