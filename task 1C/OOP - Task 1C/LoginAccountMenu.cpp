#include "LoginAccountMenu.h"

LoginAccountMenu::LoginAccountMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); 
}

void LoginAccountMenu::OutputOptions()
{

	for (int i = 0; i < app->accounts.length(); i++)
	{
		std::cout << "  " << (i + 1) << ") " << app->accounts.getListItem(i)->GetEmail() << "\n";
	}

}

bool LoginAccountMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	default: {
		int index = choice - '1';

		if (index >= 0 && index < 1)
		{
			std::string email = app->accounts.getListItem(index)->GetEmail();

			std::cout << "  Enter password for " << email << ": ";
			if (app->LoginAccount(email, Utils::GetLineFromUser()))
			{
				return true;
			}
		}
	} break;
	}

	return false;
}