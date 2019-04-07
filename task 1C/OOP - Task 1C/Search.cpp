#include "Search.h"
#include "Items.h"					//////////////////////////////// clean up 
#include "Utils.h"

Search::Search(const std::string& title, Application * app, List<Game> searchResults) : Menu(title, app), sr(searchResults)
{
	Paint(); // required in constructor
}

void Search::OutputOptions()
{
	for (int i = 0; i < sr.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, sr.getListItem(i).GetName());
	}
}

bool Search::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';
	
	if (index >= 0 && index < sr.length())
	{
		Utils u;
		Items(index, u, app, sr);
	}


	return false;
}