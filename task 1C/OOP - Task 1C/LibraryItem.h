#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date, Game, float);
		~LibraryItem();

		const Game* GetGame();
		const float GetPlayTime() const;

	private:
		const Game game;
		const Date purchased;
		float playTime;
};