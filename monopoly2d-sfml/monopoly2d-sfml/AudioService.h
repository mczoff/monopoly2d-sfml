#pragma once

#include "SFML\Audio.hpp"

class AudioService
{
public:
	sf::SoundBuffer* soundbuffer;
	sf::Sound* sound;

	AudioService();
	virtual ~AudioService();
};

