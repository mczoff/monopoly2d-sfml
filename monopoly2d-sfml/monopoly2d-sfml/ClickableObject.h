
#include "SFML\Graphics.hpp"

#include "StateObject.h"
#include "StaticGraphicObject.h"

class ClickableObject
{
	int state;

	sf::Vector2i position;

	StaticGraphicObject* source;
	StaticGraphicObject* hover;
	StaticGraphicObject* pressed;

	sf::Sprite* getsource_sprite();
	sf::Sprite* gethover_sprite();
	sf::Sprite* getpressed_sprite();

protected:
	sf::Vector2i getposition();
	void setLocation(sf::Vector2i i_position);

public:

	void loadsource_imageFromFile(char* i_path);
	void loadhover_imageFromFile(char* i_path);
	void loadpressed_imageFromFile(char* i_path);

	void refreshState(sf::Vector2i position);
	void setState(int i_state);

	int getcurrentstate();
	sf::Sprite* getcurrentSprite();

	ClickableObject();
	virtual ~ClickableObject();
};
