#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date, int);
		~Player();
		List<LibraryItem*> library = { };
	private:
};