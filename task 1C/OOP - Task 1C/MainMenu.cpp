#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
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
					app->LogoutUser();							//come back too 
				}
			}
			else
			{
				// this would need to go to a LoginMenu - similar to StoreMenu
				// instead we just set logged in to true on the main app object

				LoginUserMenu("LOGIN", app);
			}
		} break;
		case 'P':
		{
			if (app->IsUserLoggedIn())
			{
				ProfilePage("PROFILE", app);
				// this needs to go to a profile page - similar to StoreMenu
				// notice the if - this only works if somebody is logged in
			}
		} break;
		case'E':
			if (app->IsAccountLoggedIn())
			{
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					app->LogoutAccount();							//come back too 
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