#pragma once
#include "Menu.h"
#include "Search.h"
#include <string>
#include <vector>


class StoreMenu : public Menu
{

	public:
		StoreMenu(const std::string& title, Application * app);
		virtual void OutputOptions() final;
		virtual bool HandleChoice(char choice) final;
	private:
		List<Game> searchResults;

};