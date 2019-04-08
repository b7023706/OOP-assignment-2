#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void MainMenu::OutputOptions()
{

	if (app->IsAccountLoggedIn()) {

		Option('E', "Logout Email Account");
		Option('S', "Browse Store");

		if (app->IsUserLoggedIn())
		{
			Option('P', "View Profile");
			Option('L', "Logout");
		}
		else
		{
			Option('L', "Login");
		}


	}
	else
		Option('E', "Login Email Account");

}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		case 'S':
		{
			StoreMenu("STORE", app);
		} break;
		case 'L':
		{
			if (app->IsUserLoggedIn())
			{
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					app->LogoutUser();
				}
			}
			else
			{
				LoginUserMenu("LOGIN", app);
			}
		} break;
		case 'P':
		{
			if (app->IsUserLoggedIn())
			{
				ProfilePage("PROFILE", app);
			}
		} break;
		case'E':
			if (app->IsAccountLoggedIn())
			{
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					app->LogoutUser();
					app->LogoutAccount();
				}
			}
			else
			{
				LoginAccountMenu("Account Menu", app);
			}


			break;
	}

	return false;
}