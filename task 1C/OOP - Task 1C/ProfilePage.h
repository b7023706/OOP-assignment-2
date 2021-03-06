#pragma once
#include "Menu.h"
#include "Items.h"
#include "pred.h"
#include <string>
#include <vector>
#include <algorithm>

class ProfilePage : public Menu
{
public:
	ProfilePage(const std::string& title, Application * app);
	virtual void OutputOptions() final;
	virtual bool HandleChoice(char choice) final;

};