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

int Game::GetRating() const
{
	std::stringstream ss;
	ss << static_cast<int>(rating);
	//return ss.str;
	return rating;
}
void Game::SetReview(bool gameRating)
{
	const int oneHundered(100);

	if (gameRating == true) {
		like += 1;
	}
	else if (gameRating == false) {
		dislike += 1;
	}
	rating = (like / (like + dislike) * oneHundered);
}