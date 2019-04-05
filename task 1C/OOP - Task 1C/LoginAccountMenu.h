#pragma once

#include "Menu.h"

class LoginAccountMenu : public Menu
{
public:
	LoginAccountMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
};
