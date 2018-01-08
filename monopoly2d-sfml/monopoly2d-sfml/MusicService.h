#pragma once
#include "SFML\Audio\Music.hpp"

class MusicService
{
	//TODO SINGLETONE
	sf::Music* music;


public:
	//TODO PLAYLIST
	void play();
	void openFromFile(char* i_path);
	void stop();
	void pause();
	void setvolume(float i_volume);
	float getvolume();
	void clear();
	void setloop(bool i_value);
	bool isPlaying();

	MusicService();
	virtual ~MusicService();
};

