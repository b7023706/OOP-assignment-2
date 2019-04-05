#include "Items.h"

Items::Items(int index, Application * app,List<Game> list) : Menu("GAME DESCRIPTION", app), list(list)
{
	ItemOption = index;
	Paint();
}

Items::~Items()
{
}




void Items::OutputOptions()
{
	List<Game> aList;
	std::cout << "  -= " << list.getListItem(ItemOption).GetName() <<" =-\n";
	std::cout << list.getListItem(ItemOption).GetDescription() << "\n";
	std::cout << list.getListItem(ItemOption).GetCost() << "\n";
	

	if (app->IsUserLoggedIn())
	{
		std::cout << "You (" << app->GetCurrentUser()->GetUsername() << ") have " << app->GetCurrentUser()->GetCredits() << " credits\n";

		Option('P', "Buy");
	}
	
}

bool Items::HandleChoice(char choice)
{
	List<Game> aList;

	switch (choice)
	{
	case 'P': if (app->IsUserLoggedIn()) 
		{
		if (app->GetCurrentUser()->GetCredits() >= list.getListItem(ItemOption).GetCost())
		{
			app->GetCurrentUser()->SetCredits(list.getListItem(ItemOption).GetCost());
			Question("You have been billed");
			//u1->library.addAtEnd(new LibraryItem(Date(17, 6, 2018), &app.GetStore().games.getListItem(app.GetStore().games, 0)));
			//add to account
		}
		} break;
	}

	return false;
}

