#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint();
}

void LoginUserMenu::OutputOptions()
{

	for (int i = 0; i < app->GetCurrentAccount()->users.length(); i++)
	{
		std::cout << "  " << (i + 1) << ") " << app->accounts.getListItem(0)->users.getListItem(i)->GetUsername() << "\n";
	}
	
}

bool LoginUserMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	default: {
		int index = choice - '1';

		if (index >= 0 && index < app->GetCurrentAccount()->users.length())
		{
			std::string username = app->GetCurrentAccount()->users.getListItem(index)->GetUsername();

			std::cout << "  Enter password for " << username << ": ";
			if (app->LoginUser(username, Utils::GetLineFromUser()))
			{
				return true;
			}
			else
			{
				Question("Incorrect Password");
			}
			
		}
	} break;
	}

	return false;
}