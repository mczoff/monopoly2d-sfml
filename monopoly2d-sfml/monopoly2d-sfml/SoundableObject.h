#pragma once

#include "SFML\Audio.hpp"
#include "Options.h"
#include "GameWindow.h"
#include "StateObject.h"

class SoundableObject
{
	int state;

	sf::Sound* hover_sound;
	sf::SoundBuffer* hover_soundbuffer;

	sf::Sound* click_sound;
	sf::SoundBuffer* click_soundbuffer;
public:
	void sethoversound(char* i_path);
	void setclicksound(char* i_path);
	void playsound(int state);

	SoundableObject();
	virtual ~SoundableObject();
};

