#include "SoundableObject.h"



SoundableObject::SoundableObject()
{
	hover_sound = new sf::Sound();
	hover_soundbuffer = new sf::SoundBuffer();

	click_sound = new sf::Sound();
	click_soundbuffer = new sf::SoundBuffer();
}


SoundableObject::~SoundableObject()
{
}

void SoundableObject::playSound(int i_state)
{
	click_sound->setVolume(Options::getInstance()->getsoundvolume());
	hover_sound->setVolume(Options::getInstance()->getsoundvolume());

	if (i_state == StateObject::Hover && state == StateObject::None)
		if(hover_sound->getStatus() != sf::Sound::Status::Playing)
			hover_sound->play();
	if (i_state == StateObject::Click)
		click_sound->play();
	state = i_state;
}

void SoundableObject::sethoversound(char* i_path)
{
	hover_soundbuffer->loadFromFile(i_path);
	hover_sound->setBuffer(*hover_soundbuffer);
}

void  SoundableObject::setclicksound(char* i_path)
{
	click_soundbuffer->loadFromFile(i_path);
	click_sound->setBuffer(*click_soundbuffer);
}