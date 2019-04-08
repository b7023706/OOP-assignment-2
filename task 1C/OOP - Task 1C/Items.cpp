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
	List<Game> aList;

	bool gotGame = false;

	switch (choice)
	{
	case 'P': if (app->IsUserLoggedIn()) 
		{
		if (app->GetCurrentUser()->GetCredits() >= list.getListItem(ItemOption).GetCost())
		{
			
			for (int i(0); i < app->GetCurrentUser()->library.size(); i++)
			{
				if (app->GetCurrentUser()->library.at(i)->GetGame()->GetName() == list.getListItem(ItemOption).GetName())
				{
					gotGame = true;
				}
			}

			if (gotGame == false)
			{
				Question("You have been billed");
				app->GetCurrentUser()->SetCredits(list.getListItem(ItemOption).GetCost());
				app->GetCurrentUser()->library.push_back(new LibraryItem(Date(), app->GetStore().games.getListItem(ItemOption), 0.0f));
			}
			else
			{
				Question("you already own this");
			}
			

			//u1->library.addAtEnd(new LibraryItem(Date(17, 6, 2018), &app.GetStore().games.getListItem(app.GetStore().games, 0)));
			//add to account
		}
		} break;
	}

	return false;
}
