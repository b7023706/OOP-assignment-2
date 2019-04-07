#include "Utils.h"

std::string Utils::GetLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

char Utils::GetCharFromUser()
{
    return toupper(GetLineFromUser()[0]);
}

List<Game> Utils::SearchGame(Application* app, List<Game> aList)
{
	std::string input;
	input = GetLineFromUser();
	bool validSearch = false;
	int failCount = 0;
	List<Game> searchList;

	for (int i = 0; i < app->GetStore().games.length(); i++)
	{
		string name = aList.getListItem(i).GetName();
		for (int n(0); n < name.length(); n++)
		{
			if (toupper(name.substr(n, n + 1)[0]) == toupper(input.substr(0, 1)[0]))
			{
				validSearch = true;
				failCount = n;
				n = name.length();
			}
		}
		for (int k = 0; k < input.length(); k++)
		{
			if (toupper(name.substr(failCount + k, failCount + k + 1)[0]) != toupper(input.substr(k, k + 1)[0]))
			{
				validSearch = false;
			}
		}

		if (validSearch == true)
		{
			searchList.addAtEnd(aList.getListItem(i));
		}

	}
	return searchList;
}

std::string Utils::ToUpperFor(std::string name)
{
	std::string upperName;
	char temp;
	for (int i(0); i < name.length(); i++)
	{
		temp = toupper(name.substr(i, 1)[0]);
		upperName += temp;
	}
	return upperName;
}

std::string Utils::ToUpperRec(std::string name, std::string upperName, int i)
{
	char temp;
	if (i == 0)
	{
		temp = toupper(name.substr(i, 1)[0]);
		return upperName += temp;
	}
	else
	{
		return upperName += ToUpperRec(name.substr(i + 1, name.length() - 1), NULL, i + 1);
	}
}

int Utils::getRandomTime()
{
	return rand() % 50 + 10;
}