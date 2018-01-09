#pragma once

#include "VolumeControl.h"

class SoundVolumeControl : public VolumeControl
{
	void refreshvolumestate();
public:
	SoundVolumeControl();
	virtual ~SoundVolumeControl();
};

