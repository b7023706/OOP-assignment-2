#pragma once

#include <string>
#include <iostream>

class Utils
{
  public:
    static std::string GetLineFromUser();			
    static char GetCharFromUser();
	std::string ToUpperFor(std::string name);
	std::string ToUpperRec(std::string name, std::string, int);
};
