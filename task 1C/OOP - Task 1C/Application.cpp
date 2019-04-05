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
	//currentUser = currentAccount->users.getListItem(currentAccount->users, 0);

	
	for (int i = 0; i <= GetCurrentAccount()->users.length() - 1; i++) 
	{
		if (username == GetCurrentAccount()->users.getListItem(GetCurrentAccount()->users, i)->GetUsername())
		{
			if (password == GetCurrentAccount()->users.getListItem(GetCurrentAccount()->users, i)->GetPassword())
			{
				currentUser = currentAccount->users.getListItem(currentAccount->users, i);
				return true;
			}
		}
	}

}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::Load()
{
	char x;
	string total;
	ifstream Loaded;
	Loaded.open("Data");
	if (!Loaded)
	{
		Loaded.close();
	}
	else
	{
		
		while (Loaded >> x)
		{
			total = total + x;
		}
		Loaded.close();
	}



	///////////////////////////////////////////this gets the first value and converts it to integer, this is so we know how many games we need to process/////////////////////////////////////////////
	vector<char> tempLength{};
	int Length = 0;
	int pos = -1;
	//seperation
	do {
		pos++;
		tempLength.push_back(total.at(pos));
	} while (tempLength.at(pos) != '|');
	for (int i = 0; i < pos; i++)
	{
		int temp = (int)tempLength.at(i);
		temp -= 48;
		Length = Length * 10 + temp;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<string> names;
	vector<string> description;
	vector<int> price;
	for (int i = 0; i < Length; i++)
	{
		vector<char> name;
		int t = 0;
		//get name///////////////////////////////////////////////
		do {
			pos++;
			t++;
			name.push_back(total.at(pos));
		} while (total.at(pos) != '|');

		string n;
		for (int k = 0; k < t-1; k++)
		{
			n = n + name.at(k);
		}

		names.push_back(n);

		//get description//////////////////////////////////////////
		vector<char> des;
		int p = 0;
		do {
			pos++;
			p++;
			des.push_back(total.at(pos));
		} while (total.at(pos) != '|');
		
		string m;
		for (int k = 0; k < p-1; k++)
		{
			m = m + des.at(k);
		}

		description.push_back(m);


		//get cost//////////////////////////////////////////////////////////
		vector<char> cost{};
		int counter = 0;
		////seperation
		//do {
		//	pos++;
		//	counter++;
		//	cost.push_back(total.at(pos));
		//} while (total.at(pos) != '|');

		//string s;
		//for (int i = 0; i < counter; i++)
		//{
		//	s = s+ cost.at(i);
		//}
		//price.push_back(s);
		int value = 0;

		do {
			counter++;
			pos++;
			cost.push_back(total.at(pos));
		} while (total.at(pos) != '|');
		for (int i = 0; i < counter-1; i++)
		{
			int temp = (int)cost.at(i);
			temp -= 48;
			value = value * 10 + temp;
		}
		price.push_back(value);
		///////////////////////////////////////////////////////////////////////
	}


	//add them into store

	for (int i = 0; i < Length; i++)
	{
		GetStore().games.addAtEnd(Game(names.at(i), description.at(i), price.at(i), 10));
	}


}

void Application::Save(List<Game> aList)
{
	std::ofstream DataBase;
	DataBase.open("Data", ios::trunc);

	//games
	const int listLength = aList.length();
	DataBase << listLength << "|";
	for (int i = 0; i < listLength; i++)
	{
		DataBase << aList.getListItem(GetStore().games, i).GetName() << "|" << aList.getListItem(GetStore().games, i).GetDescription() << "|" << aList.getListItem(GetStore().games, i).GetCost() << "|";
	}

	//accounts
	//need to know if admin
	

	DataBase.close();
}
