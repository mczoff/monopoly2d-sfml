#include "ResolutionControl.h"



ResolutionControl::ResolutionControl()
{
	bt_down = new GameButton("src/buttons/sdown.png", "src/buttons/hdown.png", "src/buttons/pdown.png");
	bt_up = new GameButton("src/buttons/sup.png", "src/buttons/hup.png", "src/buttons/pup.png");

	bt_down->sethoversound("src/sounds/hbuttons.wav");
	bt_up->sethoversound("src/sounds/hbuttons.wav");

	videomodes = sf::VideoMode::getFullscreenModes();
	
	erasevideomode(1200);
	
	number = numbercurrentresolution();

	text = new sf::Text();

}

void ResolutionControl::erasevideomode(int i_lessthan)
{
	for (int i = 0; i < videomodes.size(); i++)
	{
		if (videomodes.at(i).width >= 1280)
			continue;
		videomodes.erase(videomodes.begin() + i);
		i--;
	}

}

ResolutionControl::~ResolutionControl()
{
	delete bt_down;
	delete bt_up;
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
	//TODO: COLOR
	refreshtext(gettextresolution(number % videomodes.size()),sf::Color::Black);
	
	getco_down()->setposition(position);
	settextposition(sf::Vector2i(position.x + getco_up()->getcurrentSprite()->getGlobalBounds().width ,position.y + getco_up()->getcurrentSprite()->getGlobalBounds().height / 4));
	getco_up()->setposition(sf::Vector2i(position.x + getco_up()->getcurrentSprite()->getGlobalBounds().width + text->getGlobalBounds().width, position.y));
	
	getco_up()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (getco_up()->isclick())
	{
		++number;
	}

	getco_down()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (getco_down()->isclick())
	{
		--number;

		if (number < 0)
			number = videomodes.size();
	}

	i_gamewindow->add(text);
	i_gamewindow->add(getco_up()->getcurrentSprite());
	i_gamewindow->add(getco_down()->getcurrentSprite());
}

ClickableObject*  ResolutionControl::getco_down()
{
	return bt_down;
}

ClickableObject*  ResolutionControl::getco_up()
{
	return bt_up;
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

int ResolutionControl::numbercurrentresolution()
{
	for (int i = 0; i < videomodes.size(); i++)
	{
		if (
			videomodes.at(i).height == Options::getInstance()->getheight()
			&& videomodes.at(i).width == Options::getInstance()->getwidth())
			return i;
	}
}

sf::VideoMode ResolutionControl::getvideomode()
{
	return videomodes.at(number % videomodes.size());
}

void ResolutionControl::playbuttonssound()
{
	bt_down->playsound(bt_down->getcurrentstate());
	bt_up->playsound(bt_up->getcurrentstate());
}