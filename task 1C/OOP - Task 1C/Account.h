#pragma once

#include <string>
#include "Player.h"
#include "Date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date);
		~Account();
		User* users[3] = { }; // TODO: replace with custom List<T> class
	private:
		std::string email;
		std::string password;
		Date created;
};