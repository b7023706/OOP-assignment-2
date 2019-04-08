#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "MainMenu.h"
#include "Date.h"


// TODO: Remove from global scope once menu system is integrated
//Application app;

void main()
{
	Application app;
	app.Load();
	// TODO: Remove call to dummy data, instead use Load and Save
	//createHardcodedTestData();
	// Create some users
	Player* u1 = new Admin("Alice", "password", Date(16, 6, 2018), 1000004);
	Player* u2 = new Player("Bob", "password", Date(19, 9, 2018), 1000);
	Player* u3 = new Player("Charlie", "password", Date(24, 9, 2018), 1204);

	// With some games in their library

	u1->library.push_back(new LibraryItem(Date(17, 6, 2018), app.GetStore().games.getListItem(0), 0.0f));
	u1->library.push_back(new LibraryItem(Date(18, 6, 2018), app.GetStore().games.getListItem(1), 0.0f));
	u2->library.push_back(new LibraryItem(Date(19, 9, 2018), app.GetStore().games.getListItem(2), 0.0f));
	u2->library.push_back(new LibraryItem(Date(19, 9, 2018), app.GetStore().games.getListItem(3), 0.0f));
	u3->library.push_back(new LibraryItem(Date(24, 9, 2018), app.GetStore().games.getListItem(3), 0.0f));
	u3->library.push_back(new LibraryItem(Date(30, 9, 2018), app.GetStore().games.getListItem(6), 0.0f));

	// Make an account and attach the users
	app.accounts.addAtEnd(new Account("alice@shu.com", "password", Date(16, 6, 2018)));
	app.accounts.getListItem(0)->users.addAtEnd(u1);
	app.accounts.getListItem(0)->users.addAtEnd(u2);
	app.accounts.getListItem(0)->users.addAtEnd(u3);

	// TODO: We need a login menu for accounts, for now we log in the only account
	app.LoginAccount("alice@shu.ac.uk", "password");


	// TODO: app.Load();
	MainMenu("MAIN MENU", &app);

	// TODO: app.Save();
	app.Save(app.GetStore().games);
}


