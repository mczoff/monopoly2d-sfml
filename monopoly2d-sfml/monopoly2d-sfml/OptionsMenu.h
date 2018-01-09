#pragma once

#include "Background.h"
#include "StaticGraphicObject.h"
#include "MusicService.h"
#include "GameButton.h"
#include "GameWindow.h"
#include "WindowCommand.h"
#include "MusicVolumeControl.h"
#include "SoundVolumeControl.h"

class OptionsMenu
{
	//TODO: DYNAMIC REGULATION
	Options* options;
	GameWindow* gamewindow;
	StaticGraphicObject* man;
	Background* background;
	GameButton* bt_exit;
	MusicService* musicservice;
	MusicVolumeControl* mvc;
	SoundVolumeControl* svc;
public:

	void show();

	OptionsMenu();
	virtual ~OptionsMenu();
};

