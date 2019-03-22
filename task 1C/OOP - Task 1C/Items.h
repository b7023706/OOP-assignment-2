#pragma once
#include <iostream>
#include "Menu.h"

class Items : public Menu
{
public :
	Items(int, Application*);
	int ItemOption;
	~Items();
	
	void OutputOptions() ;
	bool HandleChoice(char choice);
private:
	//Game getListItem(List<Game>, int);
};