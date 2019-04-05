#pragma once

#include <string>
#include <iostream>
#include "Application.h"
#include "ListT.h"

class Utils
{
  public:
    static std::string GetLineFromUser();			// might need to make it G 
    static char GetCharFromUser();
	List<Game> SearchGame(Application*, List<Game>);
};

// TODO: 2 versions of ToUpper