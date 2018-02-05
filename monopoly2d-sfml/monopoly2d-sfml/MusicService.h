#pragma once
#include "SFML\Audio\Music.hpp"

class MusicService
{
	static MusicService* instance;


	sf::Music* music;

	MusicService();
public:
	//TODO PLAYLIST
	void play();
	void openFromFile(char* i_path);
	void stop();
	void pause();
	void setvolume(int i_volume);
	float getvolume();
	void clear();
	void setloop(bool i_value);
	bool isPlaying();


	static MusicService* getInstance();
	
	virtual ~MusicService();
};

