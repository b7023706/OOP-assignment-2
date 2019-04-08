#include "StoreMenu.h"
#include "Items.h"					//////////////////////////////// clean up 
#include "Utils.h"

StoreMenu::StoreMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	for (int i = 0; i < app->GetStore().games.length(); i++)
	{
			// adding 1 so the display is nicer for the user
		Option(i + 1, app->GetStore().games.getListItem(i).GetName());
	}
	Option('S', "Search store");
}

bool StoreMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	Utils u;
	if (index >= 0 && index <  app->GetStore().games.length())
	{		
		Items(index, u, app, app->GetStore().games);
	}
	else if (toupper(choice) == 'S')
	{
		searchResults = u.SearchGame(app, app->GetStore().games, stoi(Question("Search By 1) Name, 2) Price, 3) Rating")));
		Search("SEARCH RESULTS", app, searchResults);
	}

	return false;
}
