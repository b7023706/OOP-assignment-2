#pragma once
#include "ListT.h"
#include "Game.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game> games = { }; // TODO: should be a dynamic collection
	private:
};