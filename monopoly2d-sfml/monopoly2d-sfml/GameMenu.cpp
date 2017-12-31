#include "GameMenu.h"



GameMenu::GameMenu(GameWindow* i_gamewindow)
{
	//TODO: PATH TO BACKGROUND IMAGE
	background = Background::loadBackgroundFromFile("src/backgroundmenu.png"); 
	gamewindow = i_gamewindow;
}


GameMenu::~GameMenu()
{

}

void GameMenu::show()
{
	while (gamewindow->isOpen())
	{
		gamewindow->add(background->getSprite());
		gamewindow->draw();
		gamewindow->procEvents();
		gamewindow->render();
		gamewindow->clear();

	}
}