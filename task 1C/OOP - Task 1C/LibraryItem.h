#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date, Game, float);
		~LibraryItem();

		const Game* GetGame();
		const string GetPlayTime() const;
		void SetPlayTime(float);
		const Date* GetDate();
		string GetPlayTimeSign();

	private:
		const Game game;
		const Date purchased;
		float playTime;
};