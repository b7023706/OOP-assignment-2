#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating) : name(name), description(desc), cost(cost), rating(rating)
{

}

Game::~Game()
{
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

int Game::GetCost() const
{
	return cost;
}
std::string Game::GetRating() const
{
	//std::string outputReviewRating;
	std::stringstream ss;

	//return outputReviewRating = std::to_string(static_cast<int>(reviewRating));
	//ss << static_cast<int>(reviewRating);
	//return outputReviewRating;
	return std::to_string(reviewRating);
}


void Game::SetReview(bool gameRating)
{
	const int oneHundered(100);



	if (gameRating == true)
	{
		like += 1;
	}
	if (gameRating == false)
	{
		dislike += 1;
	}

	reviewRating = like / (like + dislike) * 100;
}

//const std::string Game::GetReview() const
//{
//	 //= ss.str();
//
//}