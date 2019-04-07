#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date created, int cred) : User(username, password, created, cred)
{
}

Player::~Player()
{
	for (int i = 0; i < 2; ++i)
	{
		delete library.getListItem(i);
	}
}