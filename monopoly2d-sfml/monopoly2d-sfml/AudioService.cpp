#include "AudioService.h"



AudioService::AudioService()
{
	soundbuffer = new sf::SoundBuffer();
	sound = new sf::Sound();
}


AudioService::~AudioService()
{
}
