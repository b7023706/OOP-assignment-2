#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{


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

				LoginUserMenu("Login", app);
			}
		} break;
		case 'P':
		{
			if (app->IsUserLoggedIn())
			{
				int amount = app->GetCurrentUser()->GetCredits();
				string cred = "You have credits: ";
				cred += amount;
				Question(cred);
				// this needs to go to a profile page - similar to StoreMenu
				// notice the if - this only works if somebody is logged in
			}
		} break;
	}

	return false;
}