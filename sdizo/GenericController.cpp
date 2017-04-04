#include "stdafx.h"
#include "GenericController.h"

void GenericController::printView()
{
	structure->getStructureView()->print();
	structure->getMenu()->print();
}
