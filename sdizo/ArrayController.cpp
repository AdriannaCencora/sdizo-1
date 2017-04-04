#include "stdafx.h"
#include "ArrayController.h"

ArrayController::ArrayController()
{
	this->structure = std::make_unique<Array>();
}


void ArrayController::parseInput(std::string input)
{
	std::cout << "Data for arrayController: " << input << std::endl;
}
