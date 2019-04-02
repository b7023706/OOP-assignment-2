#include "Application.h"

#include <fstream>			// for file I/O
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
	{
		delete accounts.getListItem(accounts, i);
	}
}



//////////////////////////////////////////////////

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}



//////////////////////////////////////////////

Store& Application::GetStore()
{
	return store;
}

//////////////////////////////////////////////

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	currentAccount = accounts.getListItem(accounts, 0);

	return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: This currently always logs you in as the first user
	currentUser = currentAccount->users.getListItem(currentAccount->users, 0);

	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::Load()
{
	//std::ifstream Loaded;
	//Loaded.open("DataBaseSerialised", ios::in);
	//
	//
	//
	//
	//string data;
	//getline(Loaded, da)

	//Loaded >> data;

	//Loaded.close();

}

void Application::Save(List<Game> aList)
{
	std::ofstream DataBase;
	DataBase.open("DataBaseSerialised", ios::trunc);

	const int listLength = aList.length();
	DataBase << listLength << "|";
	for (int i = 0; i < listLength; i++)
	{
		DataBase << aList.getListItem(GetStore().games, i).GetName() << "|" << aList.getListItem(GetStore().games, i).GetDescription() << "|" << aList.getListItem(GetStore().games, i).GetCost() << "\n";
	}
	DataBase.close();
}
