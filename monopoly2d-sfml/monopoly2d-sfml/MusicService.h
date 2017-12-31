#pragma once
#include "SFML\Audio\Music.hpp"

class MusicService
{
	sf::Music* music;


public:
	
	void play();
	void openFromFile(char* i_path);
	void stop();
	void pause();
	void setvolume(float volume);
	void clear();

	bool isPlaying();

	MusicService();
	virtual ~MusicService();
};

