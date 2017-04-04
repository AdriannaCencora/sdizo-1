#include "stdafx.h"
#include "GenericController.h"

GenericController::GenericController()
{
	initialize();
}

void GenericController::printView()
{
	structure->printData();
	menu->print();
}
