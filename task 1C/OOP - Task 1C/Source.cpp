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

void main()
{
	Application app;
	app.Load();

	/*app.GetStore().games.addAtEnd(Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	app.GetStore().games.addAtEnd(Game("Braid", "A time twisting puzzle game.", 499, 15));
	app.GetStore().games.addAtEnd(Game("Factorio", "Build a complicated factory in space.", 1599, 12));
	app.GetStore().games.addAtEnd(Game("LIMBO", "Watch out for that spider.", 299, 12));
	app.GetStore().games.addAtEnd(Game("INSIDE", "What are those scientists even doing?!", 1299, 15));
	app.GetStore().games.addAtEnd(Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	app.GetStore().games.addAtEnd(Game("Half Life 3", "It's never coming out.", 5999, 18));
	app.GetStore().games.addAtEnd(Game("Castle Crashers", "A small giraffe follows you around.", 999, 18));
	app.GetStore().games.addAtEnd(Game("Brothers", "Split your brain into two thumbs.", 799, 15));*/

	// Create some users
	/*User* u1 = new Admin("Alice", "password", Date(16, 6, 2018), 1000004);
	User* u2 = new Player("Bob", "password", Date(19, 9, 2018), 1000);
	User* u3 = new Player("Charlie", "password", Date(24, 9, 2018), 1204);*/

	

	// With some games in their library

	/*Player* pp = dynamic_cast<Player*>(u1);
	if (pp != nullptr)
	{
		pp->library.push_back(new LibraryItem(Date(17, 6, 2018), app.GetStore().games.getListItem(0), 0.0f));
		pp->library.push_back(new LibraryItem(Date(18, 6, 2018), app.GetStore().games.getListItem(1), 0.0f));

		pp = dynamic_cast<Player*>(u2);
		if (pp != nullptr)
		{
			pp->library.push_back(new LibraryItem(Date(19, 9, 2018), app.GetStore().games.getListItem(2), 0.0f));
			pp->library.push_back(new LibraryItem(Date(19, 9, 2018), app.GetStore().games.getListItem(3), 0.0f));
		}
		pp = dynamic_cast<Player*>(u3);
		if (pp != nullptr)
		{
			pp->library.push_back(new LibraryItem(Date(24, 9, 2018), app.GetStore().games.getListItem(3), 0.0f));
			pp->library.push_back(new LibraryItem(Date(30, 9, 2018), app.GetStore().games.getListItem(6), 0.0f));
		}
	}*/

	// Make an account and attach the users
	/*app.accounts.addAtEnd(new Account("alice@shu.com", "password", Date(16, 6, 2018)));
	app.accounts.getListItem(0)->users.addAtEnd(u1);
	app.accounts.getListItem(0)->users.addAtEnd(u2);
	app.accounts.getListItem(0)->users.addAtEnd(u3);*/


	app.LoginAccount("alice@shu.ac.uk", "password");


	MainMenu("MAIN MENU", &app);

	app.Save(app.GetStore().games);
}


