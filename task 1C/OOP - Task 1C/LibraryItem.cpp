#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date date, Game game, float playTime, int reviewRating) : purchased(date), game(game), playTime(playTime), reviewRating(reviewRating)
{

}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::GetGame()
{
	return &game;
}

const Date* LibraryItem::GetDate()
{
	return &purchased;
}

const string LibraryItem::GetPlayTime() const
{
	string outputPlayTime;
	stringstream ssTemp;
	if (playTime < 60)
	{
		return outputPlayTime = to_string( static_cast<int>(playTime));
	}
	else if (playTime > 60 && playTime < 300)
	{
		ssTemp << setprecision(2) << playTime / 60;
		return ssTemp.str();
	}
	else
	{
		return outputPlayTime = to_string(static_cast<int>(floor(playTime / 60)));
	}
}

void LibraryItem::SetPlayTime(float randomTime)
{
	playTime += randomTime;
}

