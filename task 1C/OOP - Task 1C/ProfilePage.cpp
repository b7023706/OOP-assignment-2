#include "ProfilePage.h"

ProfilePage::ProfilePage(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfilePage::OutputOptions()
{
	//Player* pp = dynamic_cast<Player*>(app->GetCurrentUser());
	//for (int i = 0; i < pp->library.length() - 1; i++)
	//{
	//	// adding 1 so the display is nicer for the user
	//	Option(i + 1, pp->library.getListItem(pp->library, i)->GetGame()->GetName());
	//}
	for (int i(0); i < app->GetCurrentUser()->library.size() - 1; i++)
	{
		app->GetCurrentUser()->library.at(i)->GetGame()->GetName();
	}
}

bool ProfilePage::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	return false;
}

