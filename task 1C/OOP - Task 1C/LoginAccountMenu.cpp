#include "LoginAccountMenu.h"

LoginAccountMenu::LoginAccountMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginAccountMenu::OutputOptions()
{

	for (int i = 0; i < app->accounts.length(); i++)
	{
		std::cout << "  " << (i + 1) << ") " << app->accounts.getListItem(app->accounts, i)->GetEmail() << "\n";
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
			std::string email = app->accounts.getListItem(app->accounts, index)->GetEmail();

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