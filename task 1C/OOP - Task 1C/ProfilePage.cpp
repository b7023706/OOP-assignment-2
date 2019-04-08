#include "ProfilePage.h"

ProfilePage::ProfilePage(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); 
}

void ProfilePage::OutputOptions()
{
	for (int i(0); i < app->GetCurrentUser()->library.size(); i++)
	{
		Option(i + 1, app->GetCurrentUser()->library.at(i)->GetGame()->GetName());
		std::cout << "   Play Time: " + app->GetCurrentUser()->library.at(i)->GetPlayTime() + "h" << "\n\n";
	}
	Option('N', "Sort By Game Name");
	Option('D', "Sort By Date of Purchase");
	Option('C', "Add Credits");
	std::cout << "\n  " << "your credit amount is :" << app->GetCurrentUser()->GetCredits() << "\n";
	
	

	
}

bool ProfilePage::HandleChoice(char choice)
{
	int index = choice - '1';

	if (index >= 0 && index < app->GetCurrentUser()->library.size())
	{
		int temp = stoi(Question("1) Play Game, 2) review the game"));
		if (temp == 1) {

			Utils u;
			float randomTime = u.getRandomTime();
			app->GetCurrentUser()->library.at(index)->SetPlayTime(randomTime);
		}
		else if (temp == 2) {
			int temp = stoi(Question("1) Like, 2) Disklike"));
			if (temp == 1) {

			}
			else if(temp == 2){

			}
		}

	}
	if (toupper(choice) == 'C')
	{

		std::cout << "Enter Amount (100 credits = " << char(156) << "1): ";

		string temp = Utils::GetLineFromUser();
		if (temp == "")
		{
			temp = "0";
		}
		
		app->GetCurrentUser()->SetCredits(-stoi(temp));
	}
	if (toupper(choice) == 'N')
	{
		int temp = stoi(Question("1) Descending, 2) Ascending"));
		if (temp == 1)
		{
			std::sort(app->GetCurrentUser()->library.begin(), app->GetCurrentUser()->library.end(), predNameDesc());
		}
		else if(temp == 2)
		{
			std::sort(app->GetCurrentUser()->library.begin(), app->GetCurrentUser()->library.end(), predNameAsc());
		}

	}
	if (toupper(choice) == 'D')
	{
		int temp = stoi(Question("1) Oldest to newest, 2) Newest to oldest"));
		if (temp == 1)
		{
			std::sort(app->GetCurrentUser()->library.begin(), app->GetCurrentUser()->library.end(), predDateDesc());
		}
		else if (temp == 2)
		{
			std::sort(app->GetCurrentUser()->library.begin(), app->GetCurrentUser()->library.end(), predDateAsc());
		}
	}
	return false;
}
