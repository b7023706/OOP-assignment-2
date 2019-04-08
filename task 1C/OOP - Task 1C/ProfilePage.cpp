#include "ProfilePage.h"

ProfilePage::ProfilePage(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfilePage::OutputOptions()
{
	for (int i(0); i < app->GetCurrentUser()->library.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, app->GetCurrentUser()->library.getListItem(i)->GetGame().GetName() + "   Play Time: " + to_string(app->GetCurrentUser()->library.getListItem(i)->GetPlayTime()) + "h");
	}
	Option('C', "Add Credits");
	std::cout << "  " << "your credit amount is :" << app->GetCurrentUser()->GetCredits();
	

	
}

bool ProfilePage::HandleChoice(char choice)
{
	
	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentUser()->library.length())
	{
		app->GetCurrentUser()->library.getListItem(index);
		


	}
	if (toupper(choice) == 'C')
	{
		//int temp = stoi(Utils::GetLineFromUser());
		app->GetCurrentUser()->SetCredits(-stoi(Utils::GetLineFromUser()));
	}

	return false;
	
}
