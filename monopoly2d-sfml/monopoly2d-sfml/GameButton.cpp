#include "GameButton.h"



GameButton::GameButton(sf::Vector2i i_position,char* i_path_source, char* i_path_hover, char* i_path_pressed)
{
	setposition(i_position);
	loadhover_imageFromFile(i_path_hover);
	loadpressed_imageFromFile(i_path_pressed);
	loadsource_imageFromFile(i_path_source);
}


GameButton::~GameButton()
{
}

