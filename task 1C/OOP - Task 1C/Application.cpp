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
	vector<int> numOfUsers;
	vector<int> numOfItems;
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

	currentPos = (numOfGames * 4) + 1;

	for (int i(currentPos); i < separated.size(); i = i)
	{
		accountEmails.push_back(separated.at(i)); i++;
		accountPassword.push_back(separated.at(i)); i++;
		accountDate.push_back(separated.at(i)); i++;

		numOfUsers.push_back(stoi(separated.at(i))); i++;
		for (int j(0); j < numOfUsers.at(numOfUsers.size() - 1); j++)
		{
			userName.push_back(separated.at(i)); i++;
			userPassword.push_back(separated.at(i)); i++;
			userDate.push_back(separated.at(i)); i++;
			userCredits.push_back(stoi(separated.at(i))); i++;

			numOfItems.push_back(stoi(separated.at(i))); i++;
			for (int j(0); j < numOfItems.at(numOfItems.size() - 1); j++)
			{
				itemDate.push_back(separated.at(i)); i++;
				itemName.push_back(separated.at(i)); i++;
				itemTime.push_back(stoi(separated.at(i))); i++;
			}
		}
	}

	//add them into store

	for (int i(0); i < gameNames.size(); i++)
	{
		GetStore().games.addAtEnd(Game(gameNames.at(i), gameDescriptions.at(i), gamePrices.at(i), gameRatings.at(i)));
	}

	while(accountEmails.size() != 0)
	{
		stringstream ssAcc(accountDate.at(0));
		Date d;
		d.getDataFromStream(ssAcc);
		accounts.addAtEnd(new Account(accountEmails.at(0), accountPassword.at(0), d));
		for(int i(0); i < numOfUsers.size(); i++)
		{
			for (int j(0); j < numOfUsers.at(i); j++)
			{
				if (j == 0)
				{
					stringstream ssUsr(userDate.at(0));
					d.getDataFromStream(ssUsr);
					User* usr = new Admin(userName.at(0), userPassword.at(0), d, userCredits.at(0));
					accounts.getListItem(accounts.length() - 1)->users.addAtEnd(usr);
				}
				else
				{
					stringstream ssUsr(userDate.at(0));
					d.getDataFromStream(ssUsr);
					User* usr = new Player(userName.at(0), userPassword.at(0), d, userCredits.at(0));
					accounts.getListItem(accounts.length() - 1)->users.addAtEnd(usr);
				}

				
				userName.erase(userName.begin());
				userPassword.erase(userPassword.begin());
				userDate.erase(userDate.begin());
				userCredits.erase(userCredits.begin());
			}
			accountEmails.erase(accountEmails.begin());
			accountPassword.erase(accountPassword.begin());
			accountDate.erase(accountDate.begin());
		}
		for (int i(0); i < accounts.length(); i++)
		{
			for (int j(0); j < accounts.getListItem(i)->users.length(); j++)
			{
				for (int k(0); k < numOfItems.at(j); k++)
				{
					stringstream ssLbr(itemDate.at(k));
					d.getDataFromStream(ssLbr);
					Player* pp = dynamic_cast<Player*>(accounts.getListItem(i)->users.getListItem(j));
					for (int l(0); l < GetStore().games.length(); l++)
					{
						if (GetStore().games.getListItem(l).GetName() == itemName.at(k))
						{
							Game g = GetStore().games.getListItem(l);
							pp->library.push_back(new LibraryItem(d, g, itemTime.at(k)));
						}
					}
					/*itemName.erase(itemName.begin());
					itemDate.erase(itemDate.begin());
					itemTime.erase(itemTime.begin());*/
				}
			}
		}
	}

}

void Application::Save(List<Game> aList)
{
	std::ofstream DataBase;
	DataBase.open("Data", ios::trunc);

	//games

	DataBase << aList.length() << "|" << endl;
	for (int i = 0; i < aList.length(); i++)
	{
		DataBase << aList.getListItem(i).GetName() << "|" << aList.getListItem(i).GetDescription() << "|" << aList.getListItem(i).GetCost() << "|" << aList.getListItem(i).GetRating() << "|" << endl;
	}

	//accounts, Users + Libraries
	for (int i(0); i < accounts.length(); i++)
	{
		Account* a = accounts.getListItem(i);

		stringstream ssAcc; 
		a->GetDate().putDataInStream(ssAcc);

		DataBase << a->GetEmail() << "|" << a->GetPassword() << "|" << ssAcc.str() << "|" << endl;
		DataBase << to_string(a->users.length()) << "|" << endl;

		for (int j(0); j < a->users.length(); j++)
		{
			User* u = accounts.getListItem(i)->users.getListItem(j);
			Player* pp = dynamic_cast<Player*>(accounts.getListItem(i)->users.getListItem(j));

			stringstream ssUsr;
			u->GetDate().putDataInStream(ssUsr);
			
			DataBase << u->GetUsername() << "|" << u->GetPassword() << "|" << ssUsr.str() << "|" << to_string(pp->GetCredits()) << "|" << endl;
			DataBase << to_string(pp->library.size()) << "|" << endl;

			for (int k(0); k < pp->library.size(); k++)
			{
				LibraryItem* item = pp->library.at(k);

				stringstream ssItem;
				item->GetDate()->putDataInStream(ssItem);

				DataBase << ssItem.str() << "|" << item->GetGame()->GetName() << "|" << item->GetPlayTime() << "|" << endl;
			}
		}
	}

	DataBase.close();
}
