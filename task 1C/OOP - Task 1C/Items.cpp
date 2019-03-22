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

	if (app->IsUserLoggedIn())
	{
		Option('P', "Buy");
	}
	
}

bool Items::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'P': if (app->IsUserLoggedIn()) 
		{
		Question("pay up bitch");
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
