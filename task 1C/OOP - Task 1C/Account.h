#pragma once

#include <string>
#include "Player.h"
#include "Date.h"
#include "ListT.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date);
		~Account();
		const std::string& GetEmail() const;
		const std::string& GetPassword() const;
		const Date& GetDate() const;
		List<User*> users = { };
	private:
		std::string email;
		std::string password;
		Date created;
};