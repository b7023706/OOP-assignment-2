#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date date, Game game, float playTime) : purchased(date), game(game), playTime(playTime)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::GetGame()
{
	return &game;
}

const float LibraryItem::GetPlayTime() const
{
	if (playTime < 60)
	{
		return playTime;
	}
	else if (playTime > 60 && playTime < 300)
	{
		return playTime / 60;
	}
	else
	{
		return playTime;
	}
}

void LibraryItem::SetPlayTime(float randomTime)
{
	playTime = randomTime + GetPlayTime();
}
