
#include "SFML\Graphics.hpp"

enum StateClickableObject
{
	None,
	Hover,
	Click	
};

class ClickableObject
{
	int state;

	sf::Vector2i position;

	

	sf::Image* source_image;
	sf::Texture* source_texture;
	sf::Sprite* source_sprite;

	sf::Image* hover_image;
	sf::Texture* hover_texture;
	sf::Sprite* hover_sprite;

	sf::Image* pressed_image;
	sf::Texture* pressed_texture;
	sf::Sprite* pressed_sprite;

	sf::Sprite* getsource_sprite();
	sf::Sprite* gethover_sprite();
	sf::Sprite* getpressed_sprite();

protected:
	sf::Vector2i getposition();
	void setposition(sf::Vector2i i_position);

public:

	void loadsource_imageFromFile(char* i_path);
	void loadhover_imageFromFile(char* i_path);
	void loadpressed_imageFromFile(char* i_path);

	int refreshState(sf::Vector2i position);
	void setState(int i_state);

	int getcurrentstate();
	sf::Sprite* getcurrentSprite();

	ClickableObject();
	virtual ~ClickableObject();
};
