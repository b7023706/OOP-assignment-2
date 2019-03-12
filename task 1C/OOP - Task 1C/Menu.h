#pragma once
#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"


class Menu
{
public:
	Menu(const std::string& title, Application* app);

	void Paint();

	// Use this function to output all the options specific to your menu
	virtual void OutputOptions() = 0;

	// Use this function to handle the possible choices from your menu
	// Returning true means you are ready to go back to the previous menu
	// Returning false means you will stay on the same menu
	virtual bool HandleChoice(char) = 0;

protected:
	Application * app;

	void Line();
	void Line(const std::string& text);
	void Option(int id, const std::string& option);
	void Option(char id, const std::string& option);
	std::string Question(const std::string& question);

private:
	std::string title_;

	void Header();
	void Footer();
};