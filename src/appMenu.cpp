#include "appMenu.h"

#include <iostream>
appMenu::appMenu()
{
    //ctor
}

appMenu::~appMenu()
{
    //dtor
}

void appMenu::print()
{
    std::cout << "AppMenu\n";
}

std::string appMenu::getOutput()
{
    std::string out("AppMenu\n");
    return out;
}
