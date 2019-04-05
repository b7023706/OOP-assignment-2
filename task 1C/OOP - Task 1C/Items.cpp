#include "Items.h"

Items::Items(int index, Application * app) : Menu("game description", app)
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
	std::cout << "  -= " << aList.getListItem(app->GetStore().games, ItemOption).GetName() <<" =-\n";
	std::cout << aList.getListItem(app->GetStore().games, ItemOption).GetDescription() << "\n";
	std::cout << aList.getListItem(app->GetStore().games, ItemOption).GetCost() << "\n";
	

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
		if (app->GetCurrentUser()->GetCredits() >= aList.getListItem(app->GetStore().games, ItemOption).GetCost())
		{
			app->GetCurrentUser()->SetCredits(aList.getListItem(app->GetStore().games, ItemOption).GetCost());
			Question("You have been billed");
			//u1->library.addAtEnd(new LibraryItem(Date(17, 6, 2018), &app.GetStore().games.getListItem(app.GetStore().games, 0)));
			//add to account
		}
		} break;
	}

	return false;
}

//Game Items::getListItem(List<Game> gameList, int count)
//{
//	if (count == 0)
//	{
//		return gameList.first();
//	}
//	else
//	{
//		count--;
//		return getListItem(gameList.tail(), count);
//	}
//}
