#pragma once
#include <iostream>
#include "Menu.h"

class Items : public Menu
{
public :
	Items(int, Application*, List<Game>);
	int ItemOption;
	~Items();
	
	void OutputOptions() ;
	bool HandleChoice(char choice);
private:
	List<Game> list;
	//Game getListItem(List<Game>, int);
};