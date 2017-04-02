#include "ArrayController.h"

#include <iostream>
#include <memory>
#include "Array.h"

ArrayController::ArrayController()
{
    this->structure = std::make_unique<Array>();
}

ArrayController::~ArrayController()
{
    //dtor
}


void ArrayController::parseInput(std::string input)
{
    std::cout << "Data for arrayController: " << input << std::endl;
}

void ArrayController::printView()
{
    structure->getStructureView()->print();
}
