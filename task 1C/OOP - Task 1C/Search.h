#pragma once
#include "Menu.h"
#include <string>
#include <vector>


class Search : public Menu
{
public:
	Search(const std::string& title, Application * app, List<Game> searchResults);
	virtual void OutputOptions() final;
	virtual bool HandleChoice(char choice) final;
private:
	List<Game> sr;
};