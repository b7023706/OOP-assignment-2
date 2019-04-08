#pragma once

#include <string>
#include <sstream>

class Game
{
	public:
		Game(const std::string&, const std::string&, int, int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		int GetRating() const;
		void SetReview(bool);
		int GetCost() const;
	private:
		std::string name;
		std::string description;
		int cost;
		int rating;
		bool gameRating;
		int like = 1;
		int dislike = 0;
};