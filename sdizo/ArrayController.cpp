#include "stdafx.h"
#include "ArrayController.h"

#include "Array.h"
#include "ArrayMenu.h"

ArrayController::ArrayController()
{
	this->structure = std::make_unique<Array>();
}


void ArrayController::parseInput(const std::string &input)
{
	std::cout << "Data for arrayController: " << input << std::endl;
}

void ArrayController::initialize()
{
	structure = std::make_unique<Array>();
	menu = std::make_unique<ArrayMenu>();
}
