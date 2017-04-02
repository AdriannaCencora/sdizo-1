#include "ArrayMenu.h"

#include <iostream>
ArrayMenu::ArrayMenu()
{
    //ctor
}

ArrayMenu::~ArrayMenu()
{
    //dtor
}


void ArrayMenu::print()
{
    std::cout << "Temporary Array view" << std::endl;
}
std::string ArrayMenu::getOutput()
{
    return std::string("Temporary Array view\n");
}
