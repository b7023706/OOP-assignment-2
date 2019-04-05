#pragma once

#include <string>
#include "Date.h"
#include "ListT.h"

class User
{
	public:
		User(const std::string&, const std::string&, const Date, int);
		virtual ~User();
		const std::string& GetUsername() const;
		const std::string& GetPassword() const;
		int GetCredits();
		void SetCredits(int);
	private:
		std::string username;
		std::string password;
		int credits;
		Date created;
};