#include "stdafx.h"
#include "AppController.h"
#include "appMenu.h"

void AppController::parseInput(std::string input)
{
	if (input.compare("cArray") == 0)
	{
		createArrayAction();
		return;
	}
	throw new std::invalid_argument("Unknown controller input");
}

void AppController::printView()
{
	appMenu view;
	view.print();
}

void AppController::createArrayAction()
{
	controller = std::make_unique<ArrayController>();
}
