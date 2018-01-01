#pragma once

#include "SFML\Audio.hpp"
#include "GameSound.h"

#include <vector>

class SoundService
{
	std::vector<GameSound> sounds;

public:
	SoundService();
	virtual ~SoundService();
};

