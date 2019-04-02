#pragma once
#include "ListT.h"
#include "Game.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game> games = { };
	private:
};