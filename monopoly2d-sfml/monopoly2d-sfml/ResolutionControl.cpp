#include "ResolutionControl.h"



ResolutionControl::ResolutionControl()
{
	co_down = new ClickableObject();

	co_down->loadsource_imageFromFile("src/options/click_volume_down.png");
	co_down->loadhover_imageFromFile("src/options/click_volume_down.png");
	co_down->loadpressed_imageFromFile("src/options/click_volume_down.png");

	co_up = new ClickableObject();

	co_up->loadsource_imageFromFile("src/options/click_volume_up.png");
	co_up->loadhover_imageFromFile("src/options/click_volume_up.png");
	co_up->loadpressed_imageFromFile("src/options/click_volume_up.png");

	videomodes = sf::VideoMode::getFullscreenModes();
	
	text = new sf::Text();
	
}


ResolutionControl::~ResolutionControl()
{
	delete co_down;
	delete co_up;
	delete text;
}

void ResolutionControl::setlocation(sf::Vector2i i_position)
{
	position = i_position;
}

sf::Vector2i ResolutionControl::getlocation()
{
	return position;
}

void ResolutionControl::add(GameWindow* i_gamewindow)
{
	refreshtext(gettextresolution(number % videomodes.size()),sf::Color::Black);

	co_down->setposition(position);
	settextposition(sf::Vector2i(position.x + co_up->getcurrentSprite()->getGlobalBounds().width ,position.y + co_up->getcurrentSprite()->getGlobalBounds().height / 4));
	co_up->setposition(sf::Vector2i(position.x + co_up->getcurrentSprite()->getGlobalBounds().width + text->getGlobalBounds().width, position.y));
	
	if (co_up->isclick())
	{
		++number;
	}

	if (co_down->isclick())
	{
		--number;

		if (number < 0)
			number = 47;
	}

	i_gamewindow->add(text);
	i_gamewindow->add(co_up->getcurrentSprite());
	i_gamewindow->add(co_down->getcurrentSprite());
}

ClickableObject*  ResolutionControl::getco_down()
{
	return co_down;
}

ClickableObject*  ResolutionControl::getco_up()
{
	return co_up;

}

sf::Font ResolutionControl::getfont()
{
	return font;
}

void ResolutionControl::loadfontFromFile(char* i_path)
{
	if (!font.loadFromFile(i_path))
		throw 1;
	text->setFont(font);
}

void ResolutionControl::refreshtext(std::string i_text, const sf::Color i_color)
{
	text->setString(i_text);
	text->setFillColor(i_color);
}

void ResolutionControl::settextposition(sf::Vector2i i_position)
{
	text->setPosition(sf::Vector2f(i_position.x,i_position.y));
}

std::string ResolutionControl::gettextresolution(int i)
{
	std::string tmp = "";

	int bpp = videomodes.at(i).bitsPerPixel;
	int height = videomodes.at(i).height;
	int width = videomodes.at(i).width;

	tmp += std::to_string(width) + 'x' + std::to_string(height) + 'x' + std::to_string(bpp);

	return tmp;
}
