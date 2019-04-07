#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date, Game);
		~LibraryItem();

		const Game GetGame();

	private:
		const Game game;
		const Date purchased;
};