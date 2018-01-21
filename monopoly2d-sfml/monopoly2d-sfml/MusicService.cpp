#include "MusicService.h"

MusicService* MusicService::instance = NULL;

MusicService::MusicService()
{
	music = new sf::Music();
}

void MusicService::setloop(bool i_value)
{
	music->setLoop(i_value);
}


MusicService::~MusicService()
{
	delete music;
}

void MusicService::play()
{
	music->play();
}

void MusicService::openFromFile(char* i_path)
{
	music->openFromFile(i_path);
}

void MusicService::stop()
{
	music->stop();
}
void MusicService::pause()
{
	music->pause();
}

void MusicService::clear()
{
	delete music;
}

void MusicService::setvolume(float i_volume)
{
	music->setVolume(i_volume);
}

bool MusicService::isPlaying()
{
	if (music->getStatus() == sf::SoundStream::Status::Playing)
		return true;
	return false;
}

float MusicService::getvolume()
{
	return music->getVolume();
}

MusicService* MusicService::getInstance()
{
	if (instance == NULL)
		instance = new MusicService();
	return instance;
}