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

std::string Utils::ToUpperFor(std::string name)
{
	std::string upperName;
	char temp;
	for (int i(0); i > name.length(); i++)
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