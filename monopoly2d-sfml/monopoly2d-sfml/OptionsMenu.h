#pragma once

#include "Background.h"
#include "StaticGraphicObject.h"
#include "MusicService.h"
#include "GameButton.h"
#include "GameWindow.h"
#include "MusicVolumeControl.h"
#include "SoundVolumeControl.h"
#include "ResolutionControl.h"
#include "ChangeResolutionCommand.h"
#include "IShowable.h"

class OptionsMenu : public IShowable
{
	Options* options;
	GameWindow* gamewindow;
	StaticGraphicObject* man;
	Background* background;
	GameButton* bt_back;
	MusicService* musicservice;
	MusicVolumeControl* mvc;
	StaticGraphicObject* mvclogo;
	SoundVolumeControl* svc;
	StaticGraphicObject* svclogo;
	ResolutionControl* rc;
	ChangeResolutionCommand* crc;


public:

	void show();

	OptionsMenu();
	virtual ~OptionsMenu();
};

