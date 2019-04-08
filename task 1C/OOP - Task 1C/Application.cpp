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
		delete accounts.getListItem(i);
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

User* Application::GetCurrentUser() const
{
	return currentUser;
}
Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}



//////////////////////////////////////////////

Store& Application::GetStore()
{
	return store;
}

//////////////////////////////////////////////

bool Application::LoginAccount(const std::string& email, const std::string& password)
{

	for (int i = 0; i < accounts.length(); i++)
	{
		if (email == accounts.getListItem(i)->GetEmail())
		{
			if (password == accounts.getListItem(i)->GetPassword())
			{
				currentAccount = accounts.getListItem(i);
				return true;
			}
		}
	}
	return false;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{	
	for (int i = 0; i < GetCurrentAccount()->users.length(); i++) 
	{
		if (username == GetCurrentAccount()->users.getListItem(i)->GetUsername())
		{
			if (password == GetCurrentAccount()->users.getListItem(i)->GetPassword())
			{
				currentUser = currentAccount->users.getListItem(i);
				return true;
			}
		}
	}
	return false;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::LogoutAccount()
{
	currentAccount = nullptr;
}

void Application::Load()
{
	string total;
	ifstream Loaded;
	Loaded.open("Data");
	// store stuff
	vector<string> names;
	vector<string> descriptions;
	vector<int> prices;
	vector<int> ratings;
	// user stuff
	vector<string> userName;
	vector<string> userGame;
	vector<int> credits;
	vector<float> playTime;


	vector<string> input;
	vector<string> separated;
	string line;
	string objects;


	while (getline(Loaded, line))
	{
		input.push_back(line);
	}

	Loaded.close();

	for (int i(0); i < input.size(); i++)
	{
		stringstream ss(input.at(i));
		while (getline(ss, objects, '|'))
		{
			separated.push_back(objects);
		}
	}



	for (int j(0); j < separated.size(); j = j + 4)
	{
		for (int k(0); k < 4; k++)
		{
			switch (k)
			{
			case 0:
				names.push_back(separated.at(j));
				break;
			case 1:
				descriptions.push_back(separated.at(j + 1));
				break;
			case 2:
				prices.push_back(stoi(separated.at(j + 2)));
				break;
			case 3:
				ratings.push_back(stoi(separated.at(j + 3)));
				break;
			}
		}
	}


	//add them into store

	for (int i = 0; i < names.size(); i++)
	{
		GetStore().games.addAtEnd(Game(names.at(i), descriptions.at(i), prices.at(i), ratings.at(i)));
	}


}

void Application::Save(List<Game> aList)
{
	std::ofstream DataBase;
	DataBase.open("Data", ios::trunc);

	//games

	for (int i = 0; i < aList.length(); i++)
	{
		DataBase << aList.getListItem(i).GetName() << "|" << aList.getListItem(i).GetDescription() << "|" << aList.getListItem(i).GetCost() << "|" << aList.getListItem(i).GetRating() << "|" << endl;
	}

	//accounts
	//need to know if admin


	DataBase.close();
}
