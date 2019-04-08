#include "Items.h"

Items::Items(int index, Utils u, Application * app, List<Game> list) : list(list), Menu(u.ToUpperFor(list.getListItem(index).GetName()), app)
{
	ItemOption = index;
	Paint();
}

Items::~Items()
{
}




void Items::OutputOptions()
{
	std::cout << "  " << list.getListItem(ItemOption).GetDescription() << "\n";
	std::cout << "  " << list.getListItem(ItemOption).GetCost() << "\n";


	if (app->IsUserLoggedIn())
	{
		std::cout << "You (" << app->GetCurrentUser()->GetUsername() << ") have " << app->GetCurrentUser()->GetCredits() << " credits\n";
		
		Option('P', "Buy");
	}
	
}

bool Items::HandleChoice(char choice)
{
	Player* pp = dynamic_cast<Player*>(app->GetCurrentUser());

	List<Game> aList;

	bool gotGame = false;

	switch (choice)
	{
	case 'P': if (app->IsUserLoggedIn()) 
		{
		if (app->GetCurrentUser()->GetCredits() >= list.getListItem(ItemOption).GetCost())
		{
			
			for (int i(0); i < pp->library.size(); i++)
			{
				if (pp->library.at(i)->GetGame()->GetName() == list.getListItem(ItemOption).GetName())
				{
					gotGame = true;
				}
			}

			if (gotGame == false)
			{
				Question("You have been billed");
				app->GetCurrentUser()->SetCredits(list.getListItem(ItemOption).GetCost());
				pp->library.push_back(new LibraryItem(Date(), app->GetStore().games.getListItem(ItemOption), 0.0f));
			}
			else
			{
				Question("you already own this");
			}
		
		}
		} break;
	}

	return false;
}
