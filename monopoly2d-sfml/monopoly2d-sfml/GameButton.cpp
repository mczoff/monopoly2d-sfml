#include "GameButton.h"



GameButton::GameButton(char* i_path_source, char* i_path_hover, char* i_path_pressed)
{
	loadhover_imageFromFile(i_path_hover);
	loadpressed_imageFromFile(i_path_pressed);
	loadsource_imageFromFile(i_path_source);
}


GameButton::~GameButton()
{
}

void GameButton::setlocation(sf::Vector2i i_position)
{
	ClickableObject::setPosition(i_position);
}