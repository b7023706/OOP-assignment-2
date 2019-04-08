#include "User.h"

User::User(const std::string& username, const std::string& password, const Date created, int creds) : username(username), password(password), created(created), credits(creds)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const std::string& User::GetPassword() const
{
	return password;
}

int User::GetCredits()
{
	return credits;
}

void User::SetCredits(int cost)
{
	credits -= cost;
}