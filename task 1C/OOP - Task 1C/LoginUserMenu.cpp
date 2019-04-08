#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginUserMenu::OutputOptions()
{

	for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
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

		if (index >= 0 && index < 3) // TODO: Hardcoded, change when using List<T>
		{
			std::string username = app->GetCurrentAccount()->users.getListItem(index)->GetUsername();

			std::cout << "  Enter password for " << username << ": ";
			if (app->LoginUser(username, Utils::GetLineFromUser()))
			{
				return true;
			}
			
		}
	} break;
	}

	return false;
}