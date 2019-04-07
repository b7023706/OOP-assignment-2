#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date date, Game game, float playTime) : purchased(date), game(game), playTime(playTime)
{
}

LibraryItem::~LibraryItem()
{
}

const Game LibraryItem::GetGame()
{
	return game;
}

const float LibraryItem::GetPlayTime() const
{
	return playTime;
}