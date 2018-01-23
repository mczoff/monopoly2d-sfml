#include "NumericControl.h"



NumericControl::NumericControl()
{
	bt_down = new GameButton("src/buttons/sdown.png", "src/buttons/hdown.png", "src/buttons/pdown.png");
	bt_up = new GameButton("src/buttons/sup.png", "src/buttons/hup.png", "src/buttons/pup.png");

	bt_down->sethoversound("src/sounds/hbuttons.wav");
	bt_up->sethoversound("src/sounds/hbuttons.wav");

	text = new sf::Text();
	text->setCharacterSize(48);
	

	setvalue(0);
	setmin(0);
	setmax(255);
}


NumericControl::~NumericControl()
{
	delete text;
	delete bt_down;
	delete bt_up;
} 

int NumericControl::getvalue()
{
	return value;
}

void NumericControl::incvalue(int i_value)
{
	if (value + i_value >= max)
		return;
	value += i_value;
}

void NumericControl::decvalue(int i_value)
{
	if (value - i_value < min)
		return;
	value -= i_value;
}

void NumericControl::setmin(int i_min)
{
	min = i_min;
}

void NumericControl::setmax(int i_max)
{
	max = i_max;
}

void NumericControl::setvalue(int i_value)
{
	value = i_value;
}

sf::Font NumericControl::getfont()
{
	return font;
}

void NumericControl::setlocation(sf::Vector2i i_position)
{
	position = i_position;
}

sf::Vector2i NumericControl::getlocation()
{
	return position;
}

ClickableObject*  NumericControl::getco_down()
{
	return bt_down;
}

ClickableObject*  NumericControl::getco_up()
{
	return bt_up;
}

void NumericControl::playbuttonssound()
{
	bt_down->playsound(bt_down->getcurrentstate());
	bt_up->playsound(bt_up->getcurrentstate());
}


void NumericControl::loadfontFromFile(char* i_path)
{
	if (!font.loadFromFile(i_path))
		throw 1;
	text->setFont(font);
}

void NumericControl::settextposition(sf::Vector2i i_position)
{
	text->setPosition(sf::Vector2f(i_position.x, i_position.y));
}


void NumericControl::add(GameWindow* i_gamewindow)
{
	//TODO: COLOR
	refreshtext(sf::Color::Black);

	getco_down()->setposition(position);
	settextposition(sf::Vector2i(position.x + getco_up()->getcurrentSprite()->getGlobalBounds().width, position.y + getco_up()->getcurrentSprite()->getGlobalBounds().height / 4));
	getco_up()->setposition(sf::Vector2i(position.x + getco_up()->getcurrentSprite()->getGlobalBounds().width + text->getGlobalBounds().width, position.y));
	
	getco_down()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	
	getco_up()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (getco_up()->isclick())
		incvalue();

	getco_down()->refreshState(sf::Mouse::getPosition(*GameWindow::getInstance()->getWindow()));
	if (getco_down()->isclick())
		decvalue();

	i_gamewindow->add(text);
	i_gamewindow->add(getco_up()->getcurrentSprite());
	i_gamewindow->add(getco_down()->getcurrentSprite());
}

void NumericControl::refreshtext(const sf::Color i_color)
{
	text->setString(std::to_string(value));
	text->setFillColor(i_color);
}