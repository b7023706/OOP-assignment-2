#pragma once

#include <string>
#include <iostream>
//#include <algorithm>
#include "Application.h"
#include "ListT.h"

class Utils
{
  public:
    static std::string GetLineFromUser();			// might need to make it G 
    static char GetCharFromUser();
	List<Game> SearchGame(Application*, List<Game>, int);
	std::string ToUpperFor(std::string name);
	std::string ToUpperRec(std::string name, std::string, int);
	/*std::vector<LibraryItem> SortByName(Application* app);*/
	int getRandomTime();

};