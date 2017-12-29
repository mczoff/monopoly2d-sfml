#pragma once


class Options
{
	static Options* instance;

	//TODO: CHECK CUSTOM OPTIONS 

	char* nameWindow;
	int width;
	int height;

	Options();
public:
	static Options* getInstance();

	int getwidth();
	int getheight();
	char* getnameWindow();

	void setwidth(int inner_width);
	void setheight(int inner_height);
	void setnameWindow(char* inner_name);

	void loadDefault();

	
	~Options();
};

