#include "LogoService.h"



LogoService::LogoService() :
	thread(&LogoService::showinglogo, this) 
{
}


LogoService::~LogoService()
{
}

void LogoService::showinglogo()
{
	mutex.lock();
	
	

	mutex.unlock();
}

void LogoService::showlogo()
{
	thread.launch();
	thread.terminate();
}

void LogoService::setparams(double i_seconds, GameWindow* i_window, double i_pow)
{
	seconds = i_seconds;
	window = i_window;
	pow = i_pow;
}

void LogoService::loadlogo(char* i_path)
{
	logo = Logo::loadLogoFromFile(i_path);
}

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//struct ML
//{
//	sf::Mutex mutex;
//	size_t data;
//};
//
//
//
//void logic(ML * ml)
//{
//	while (true)
//	{
//		sf::sleep(sf::seconds(1));
//		sf::Lock(ml->mutex);
//		++ml->data;
//		if (ml->data == 3)
//		{
//			ml->data = 0;
//		}
//	}
//
//}
//
//
//
//
//
//
//
//int main()
//{
//	sf::RenderWindow wnd(sf::VideoMode(600, 400), "timer test");
//	sf::RectangleShape rects[3] =
//	{
//		sf::RectangleShape(sf::Vector2f(50,50)) ,
//		sf::RectangleShape(sf::Vector2f(75,75)) ,
//		sf::RectangleShape(sf::Vector2f(100,100))
//	};
//
//	rects[0].setFillColor(sf::Color::Red);
//	rects[1].setFillColor(sf::Color::Blue);
//	rects[2].setFillColor(sf::Color::Green);
//
//	ML rect_st;
//	rect_st.data = 0;
//	sf::Thread th(logic, &rect_st);
//	th.launch();
//	while (wnd.isOpen())
//	{
//
//		sf::Event event;
//		while (wnd.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				wnd.close();
//		}
//		wnd.clear();
//		rect_st.mutex.lock();//sf::Lock  lock(rect_st.mutex) ;
//		wnd.draw(rects[rect_st.data]);
//		rect_st.mutex.unlock();
//		wnd.display();
//	}
//	th.terminate();
//
//
//}