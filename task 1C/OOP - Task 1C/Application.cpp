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
	// Games data
	vector<string> gameNames;
	vector<string> gameDescriptions;
	vector<int> gamePrices;
	vector<int> gameRatings;
	// Account data
	vector<string> accountEmails;
	vector<string> accountPassword;
	vector<string> accountDate;
	// User Data
	vector<string> userName;
	vector<string> userPassword;
	vector<string> userDate;
	vector<int> userCredits;
	// library data
	vector<string> itemDate;
	vector<string> itemName;
	vector<float> itemTime;


	vector<string> input;
	vector<string> separated;
	string line;
	string objects;

	int numOfGames;
	int currentPos = 0;


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

	numOfGames = stoi(separated.at(0));

	for (int j(1); j < (numOfGames * 4); j = j + 4)
	{
		for (int k(0); k < 4; k++)
		{
			switch (k)
			{
			case 0:
				gameNames.push_back(separated.at(j));
				break;
			case 1:
				gameDescriptions.push_back(separated.at(j + 1));
				break;
			case 2:
				gamePrices.push_back(stoi(separated.at(j + 2)));
				break;
			case 3:
				gameRatings.push_back(stoi(separated.at(j + 3)));
				break;
			}
		}
	}

	currentPos = (numOfGames * 4);

	for (int i(currentPos); i < separated.size(); i++)
	{
		accountEmails.push_back(separated.at(i));
		accountPassword.push_back(separated.at(i + 1));
		accountDate.push_back(separated.at(i + 2));

		int numOfUsers = stoi(separated.at(i + 3));
		for (int j(0); j < numOfUsers; j = j + 4)
		{
			userName.push_back(separated.at(i + 3 + j));
			userPassword.push_back(separated.at(i + 4 + j));
			userDate.push_back(separated.at(i + 5 + j));
			userCredits.push_back(stoi(separated.at(i + 6 + j)));
		}

		i = i + (numOfUsers * 4);

		int numOfItems = stoi(separated.at(i));
		for (int j(0); j < numOfItems; j = j + 3)
		{
			itemDate.push_back(separated.at(i + j + 1));
			itemName.push_back(separated.at(i + j + 2));
			itemTime.push_back(stoi(separated.at(i + j + 3)));
		}

		i = i + (numOfItems * 3);
	}

	//add them into store

	for (int i = 0; i < gameNames.size(); i++)
	{
		GetStore().games.addAtEnd(Game(gameNames.at(i), gameDescriptions.at(i), gamePrices.at(i), gameRatings.at(i)));
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
