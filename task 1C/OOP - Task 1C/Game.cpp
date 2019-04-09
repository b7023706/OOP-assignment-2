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
	return rating;
}

void Game::SetReview(bool gameRating)
{
	if (gameRating == true)
	{
		like += 1;
	}
	if (gameRating == false)
	{
		dislike += 1;
	}

	rating = like / (like + dislike) * 100;

}

std::string Game::GetReview()
{
	return std::to_string(rating);
}