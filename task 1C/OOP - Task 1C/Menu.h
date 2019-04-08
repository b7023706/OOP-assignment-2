#pragma once
#include <iostream>
#include <string>
#include "Application.h"
#include "Account.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Utils.h"
#include "ListT.h"


class Menu
{
public:
	Menu(const std::string& title, Application* app);

	void Paint();

	virtual void OutputOptions() = 0;
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