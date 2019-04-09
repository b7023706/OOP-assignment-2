#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date created) : email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < 3; ++i)
	{
		delete users.getListItem(i);
	}
}

const std::string& Account::GetEmail() const
{
	return email;
}
const std::string& Account::GetPassword() const
{
	return password;
}

const Date& Account::GetDate() const
{
	return created;
}