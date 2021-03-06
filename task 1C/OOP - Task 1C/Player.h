#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include <vector>

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date, int);
		~Player();
		vector<LibraryItem*> library;
		int GetCredits();
		void SetCredits(int);
	private:
		int credits;
};