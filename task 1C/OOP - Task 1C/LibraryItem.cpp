#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date date, Game* game) : purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

const Game* LibraryItem::GetGame()
{
	return game;
}