#pragma once

#include <string>
#include <iostream>

class Utils
{
  public:
    static std::string GetLineFromUser();			// might need to make it G 
    static char GetCharFromUser();
	void SearchGame(std::string);
};

// TODO: 2 versions of ToUpper