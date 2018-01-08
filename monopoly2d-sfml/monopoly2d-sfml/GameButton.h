#pragma once
#include <functional>

#include "SFML\Graphics.hpp"

#include "ClickableObject.h"
#include "SoundableObject.h"


class GameButton : public ClickableObject, public SoundableObject
{
	//TODO: SHOW CLICK ON BUTTON
public:

	void setlocation(sf::Vector2i i_position);

	GameButton(char* i_path_source, char* i_path_hover, char* i_path_pressed);
	virtual ~GameButton();
};

