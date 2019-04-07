#pragma once

#include <string>
#include <iostream>
#include "Application.h"
#include "ListT.h"

class Utils
{
  public:
    static std::string GetLineFromUser();
    static char GetCharFromUser();
	List<Game> SearchGame(Application*, List<Game>);
	std::string ToUpperFor(std::string name);
	std::string ToUpperRec(std::string name, std::string, int);
};
