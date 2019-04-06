#pragma once

#include <string>
#include <vector>
#include "User.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date);
		~Player();
		vector<LibraryItem*> library;
		//User* user;
		//virtual List<LibraryItem*> getLibrary() override;
	private:
};