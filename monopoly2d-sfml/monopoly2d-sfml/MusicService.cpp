#include "MusicService.h"



MusicService::MusicService()
{
	music = new sf::Music();
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

void MusicService::setvolume(float volume)
{
	music->setVolume(volume);
}

bool MusicService::isPlaying()
{
	if (music->getStatus() == sf::SoundStream::Status::Playing)
		return true;
	return false;
}
