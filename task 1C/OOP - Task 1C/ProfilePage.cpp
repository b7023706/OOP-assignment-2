#include "ProfilePage.h"

ProfilePage::ProfilePage(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); 
}

void ProfilePage::OutputOptions()
{
	Player* pp = dynamic_cast<Player*>(app->GetCurrentUser());
	for (int i(0); i < pp->library.size(); i++)
	{
		Option(i + 1, pp->library.at(i)->GetGame()->GetName());
		std::cout << "   Play Time: " + pp->library.at(i)->GetPlayTime() + "h" << "\n";
	}

	std::cout << "\n  " << "your credit amount is :" << pp->GetCredits() << "\n\n";

	Option('N', "Sort By Game Name");
	Option('D', "Sort By Date of Purchase");
	Option('C', "Add Credits");
	
	
	Admin* pa = dynamic_cast<Admin*>(pp);
	if (pa != nullptr)
	{
		Option('M', "Manage Users");
	}

	
}

bool ProfilePage::HandleChoice(char choice)
{
	int index = choice - '1';
	Player* pp = dynamic_cast<Player*>(app->GetCurrentUser());
	if (index >= 0 && index < pp->library.size())
	{
		Utils u;
		float randomTime = u.getRandomTime();
		pp->library.at(index)->SetPlayTime(randomTime);

	}
	if (toupper(choice) == 'C')
	{

		std::cout << "Enter Amount (100 credits = " << char(156) << "1): ";

		string temp = Utils::GetLineFromUser();
		if (temp == "")
		{
			temp = "0";
		}
		
		pp->SetCredits(-stoi(temp));
	}
	if (toupper(choice) == 'N')
	{
		int temp = stoi(Question("1) Descending, 2) Ascending"));
		if (temp == 1)
		{
			std::sort(pp->library.begin(), pp->library.end(), predNameDesc());
		}
		else if(temp == 2)
		{
			std::sort(pp->library.begin(), pp->library.end(), predNameAsc());
		}

	}
	if (toupper(choice) == 'D')
	{
		int temp = stoi(Question("1) Oldest to newest, 2) Newest to oldest"));
		if (temp == 1)
		{
			std::sort(pp->library.begin(), pp->library.end(), predDateDesc());
		}
		else if (temp == 2)
		{
			std::sort(pp->library.begin(), pp->library.end(), predDateAsc());
		}
	}
	if (toupper(choice) == 'M')
	{
		Admin* pa = dynamic_cast<Admin*>(pp);
		if (pa != nullptr)
		{
			for (int i(1); i < app->GetCurrentAccount()->users.length(); i++)
			{
				std::cout << "\n  " << to_string(i) << ") Delete " << app->GetCurrentAccount()->users.getListItem(i)->GetUsername();
			}
			std::cout << "\n  " << to_string(app->GetCurrentAccount()->users.length()) << ") " << "Add new user\n\n";
			string input = Question("Choose an option");
			int admChoice = 0;
			if(input != "")
				int admChoice = stoi(input);

			if (admChoice > 0 && admChoice < app->GetCurrentAccount()->users.length())
			{
				app->GetCurrentAccount()->users.deleteOne(app->GetCurrentAccount()->users.getListItem(admChoice));
			}
			else if (admChoice == app->GetCurrentAccount()->users.length())
			{
				User* pu = new Player(Question("Enter a Username"), Question("Enter a Password"), Date(), 0);
				app->accounts.getListItem(0)->users.addAtEnd(pu);
			}
		}
	}
	return false;
}
