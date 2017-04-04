#include "stdafx.h"
#include "AppController.h"

void AppController::parseInput(std::string input)
{
	if (input.compare("cArray") == 0)
	{
		createArrayAction();
		return;
	}
	throw new std::invalid_argument("Unknown controller input");
}

void AppController::createArrayAction()
{
	controller = std::make_unique<ArrayController>();
}

void AppController::printView()
{
	appMenu view;
	view.print();
}