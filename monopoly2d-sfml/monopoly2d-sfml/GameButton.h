#pragma once

#include "SFML\Graphics.hpp"

#include "ClickableObject.h"
#include "SoundableObject.h"

class GameButton : public ClickableObject, public SoundableObject
{
public:
	GameButton(sf::Vector2i i_position, char* i_path_source, char* i_path_hover, char* i_path_pressed);
	virtual ~GameButton();
};

