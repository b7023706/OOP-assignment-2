#pragma once
#include <iostream>
#include "Menu.h"

class Items : public Menu
{
public :
	Items(int, Utils, Application*, List<Game>);
	int ItemOption;
	~Items();
	
	void OutputOptions();
	bool HandleChoice(char choice);
private:
	std::string title;
	std::string upperTitle;
	List<Game> list;
};