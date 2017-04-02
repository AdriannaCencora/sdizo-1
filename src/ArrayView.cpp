#include "ArrayView.h"

#include <iostream>

ArrayView::ArrayView()
{
    //ctor
}

ArrayView::~ArrayView()
{
    //dtor
}

void ArrayView::print()
{
    std::cout << "Temporary Array view" << std::endl;
}
std::string ArrayView::getOutput()
{
    return std::string("Temporary Array view\n");
}
