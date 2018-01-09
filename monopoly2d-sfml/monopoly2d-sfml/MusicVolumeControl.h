#pragma once

#include "VolumeControl.h"

class MusicVolumeControl : public VolumeControl
{
	void refreshvolumestate();
public:
	MusicVolumeControl();
	virtual ~MusicVolumeControl();
};

