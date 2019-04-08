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
		int GetCost() const;
		std::string GetRating() const;
		void SetReview(bool gameRating);
		//const std::string GetReview() const;
	private:
		std::string name;
		std::string description;
		int cost;


		int rating;
		int reviewRating;
		float like = 0;
		float dislike = 0;
};