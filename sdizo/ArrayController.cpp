#include "stdafx.h"
#include "ArrayController.h"

#include "Array.h"
#include "ArrayMenu.h"

void ArrayController::parseInput(const std::string &input)
{
	std::cout << "Data for arrayController: " << input << std::endl;
}

void ArrayController::init()
{
	structure = std::make_unique<Array>();
	menu = std::make_unique<ArrayMenu>();
}
