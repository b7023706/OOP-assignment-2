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
Application app;

void createHardcodedTestData()
{
	// Setup store with some games
	app.GetStore().games.addAtEnd(Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	app.GetStore().games.addAtEnd(Game("Braid", "A time twisting puzzle game.", 499, 15));
	app.GetStore().games.addAtEnd(Game("Factorio", "Build a complicated factory in space.", 1599, 12));
	app.GetStore().games.addAtEnd(Game("LIMBO", "Watch out for that spider.", 299, 12));
	app.GetStore().games.addAtEnd(Game("INSIDE", "What are those scientists even doing?!", 1299, 15));
	app.GetStore().games.addAtEnd(Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	app.GetStore().games.addAtEnd(Game("Half Life 3", "It's never coming out.", 5999, 18));
	app.GetStore().games.addAtEnd(Game("Castle Crashers", "A small giraffe follows you around.", 999, 18));
	app.GetStore().games.addAtEnd(Game("Brothers", "Split your brain into two thumbs.", 799, 15));

	// Create some users
	Player* u1 = new Admin("Alice", "password", Date(16, 6, 2018));
	Player* u2 = new Player("Bob", "password", Date(19, 9, 2018));
	Player* u3 = new Player("Charlie", "password", Date(24, 9, 2018));

	// With some games in their library
	u1->library[0] = new LibraryItem(Date(17, 6, 2018), &app.GetStore().games.getListItem(app.GetStore().games, 0));
	u1->library[0] = new LibraryItem(Date(18, 6, 2018), &app.GetStore().games.getListItem(app.GetStore().games, 1));
	u2->library[0] = new LibraryItem(Date(19, 9, 2018), &app.GetStore().games.getListItem(app.GetStore().games, 2));
	u2->library[0] = new LibraryItem(Date(19, 9, 2018), &app.GetStore().games.getListItem(app.GetStore().games, 3));
	u3->library[0] = new LibraryItem(Date(24, 9, 2018), &app.GetStore().games.getListItem(app.GetStore().games, 3));
	u3->library[0] = new LibraryItem(Date(30, 9, 2018), &app.GetStore().games.getListItem(app.GetStore().games, 6));

	// Make an account and attach the users
	app.accounts[0] = new Account("alice@shu.com", "password", Date(16, 6, 2018));
	app.accounts[0]->users[0] = u1;
	app.accounts[0]->users[1] = u2;
	app.accounts[0]->users[2] = u3;

	// TODO: We need a login menu for accounts, for now we log in the only account
	app.LoginAccount("alice@shu.ac.uk", "password");
}

//char showMainMenuAndGetUserChoice()
//{
//	system("CLS");
//	std::cout << "                    \n";
//	std::cout << "  -= GAME LIBRARY =-\n";
//	std::cout << "                    \n";
//	std::cout << "  S) Browse Store   \n";
//
//	if (app.IsUserLoggedIn())
//	{
//		std::cout << "  L) Logout of " << app.GetCurrentUser()->GetUsername() << "\n";
//		// TODO: User profile option
//	}
//	else
//	{
//		std::cout << "  L) Login      \n";
//	}
//
//	std::cout << "                    \n";
//	std::cout << "  B) Exit           \n";
//	std::cout << "                    \n";
//	std::cout << "                    \n";
//	std::cout << "  >>> ";
//
//	return Utils::GetCharFromUser();
//}
//
//char showStoreMenuAndGetUserChoice()
//{
//	system("CLS");
//	std::cout << "                    \n";
//	std::cout << "  -= STORE =-       \n";
//	std::cout << "                    \n";
//
//	// Output game list
//	for (int i = 0; i < 9; i++) // TODO: Hardcoded, change when using List<T>
//	{
//		std::cout << "  " << (i + 1) << ") " << app.GetStore().games[i]->GetName() << "\n";
//	}
//
//	// TODO: Implement search store option
//
//	// Output rest of menu
//	std::cout << "                    \n";
//	std::cout << "  B) Back           \n";
//	std::cout << "                    \n";
//	std::cout << "                    \n";
//	std::cout << "  >>> ";
//
//	return Utils::GetCharFromUser();
//}
//
//char showLoginUserMenuAndGetUserChoice(Account *account)
//{
//	system("CLS");
//	std::cout << "                    \n";
//	std::cout << "  -= LOGIN =-       \n";
//	std::cout << "                    \n";
//
//	// Output user list
//	for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
//	{
//		std::cout << "  " << (i + 1) << ") " << account->users[i]->GetUsername() << "\n";
//	}
//
//	// Output rest of menu
//	std::cout << "                    \n";
//	std::cout << "  B) Back           \n";
//	std::cout << "                    \n";
//	std::cout << "                    \n";
//	std::cout << "  >>> ";
//
//	return Utils::GetCharFromUser();
//}
//
//char showGameMenuAndGetUserChoice(Game* game)
//{
//	system("CLS");
//	std::cout << "                                  \n";
//	std::cout << "  -= " << game->GetName() << " =- \n";
//	std::cout << "                                  \n";
//	std::cout << "  " << game->GetDescription() << "\n";
//	std::cout << "                                  \n";
//
//	if (app.IsUserLoggedIn())
//	{
//		std::cout << "  P) Purchase for " << (game->GetCost() / 100.0f) << "\n";
//		std::cout << "                                                      \n";
//	}
//
//	std::cout << "  B) Back                   \n";
//	std::cout << "                            \n";
//	std::cout << "                            \n";
//	std::cout << "  >>> ";
//
//	return Utils::GetCharFromUser();
//}
//
//void gameMenu(Game* game)
//{
//	bool readyToGoBack = false;
//
//	while (readyToGoBack == false)
//	{
//		int choice = showGameMenuAndGetUserChoice(game);
//
//		switch (choice)
//		{
//			case 'P': {
//				if (app.IsUserLoggedIn())
//				{
//					// TODO: Implement buying from the store
//				}
//			} break;
//			case 'B': {
//				readyToGoBack = true;
//			} break;
//		}
//	}
//}
//
//void storeMenu()
//{
//	bool readyToGoBack = false;
//
//	while (readyToGoBack == false)
//	{
//		int choice = showStoreMenuAndGetUserChoice();
//
//		switch (choice)
//		{
//			case 'B': {
//				readyToGoBack = true;
//			} break;
//			default: {
//				int index = choice - '1';
//
//				if (index >= 0 && index < 9) // TODO: Hardcoded, change when using List<T>
//				{
//					gameMenu(app.GetStore().games[index]);
//				}
//			} break;
//		}
//	}
//}
//
//void loginUserMenu()
//{
//	bool readyToGoBack = false;
//
//	while (readyToGoBack == false)
//	{
//		int choice = showLoginUserMenuAndGetUserChoice(app.GetCurrentAccount());
//
//		switch (choice)
//		{
//			case 'B': {
//				readyToGoBack = true;
//			} break;
//			default: {
//				int index = choice - '1';
//
//				if (index >= 0 && index < 3) // TODO: Hardcoded, change when using List<T>
//				{
//					std::string username = app.GetCurrentAccount()->users[index]->GetUsername();
//
//					std::cout << "  Enter password for " << username << ": ";
//					if (app.LoginUser(username, Utils::GetLineFromUser()))
//					{
//						readyToGoBack = true;
//					}
//				}
//			} break;
//		}
//	}
//}


//worked out
//void mainMenu()
//{
//	bool wantsToExit = false;
//
//	while (wantsToExit == false)
//	{
//		int choice = showMainMenuAndGetUserChoice();
//
//		switch (choice)
//		{
//			case 'S': {
//				storeMenu();
//			} break;
//			case 'L': {
//				if (app.IsUserLoggedIn())
//				{
//					app.LogoutUser();
//				}
//				else
//				{
//					loginUserMenu();
//				}
//			} break;
//			case 'B': {
//				wantsToExit = true;
//			} break;
//		}
//	}
//}

void main()
{

	// TODO: Remove call to dummy data, instead use Load and Save
	createHardcodedTestData();



	// TODO: app.Load();
	MainMenu("MAIN MENU", &app);

	// TODO: app.Save();
}