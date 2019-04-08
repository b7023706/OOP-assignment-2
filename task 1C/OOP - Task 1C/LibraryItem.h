#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date, Game, float, int);
		~LibraryItem();

		const Game* GetGame();
		const string GetPlayTime() const;
		const string GetReview() const;
		void SetReview();
		void SetPlayTime(float);
		const Date* GetDate();

	private:
		const Game game;
		const Date purchased;
		float playTime;
		int reviewRating;
		int like;
		int dislike;
};