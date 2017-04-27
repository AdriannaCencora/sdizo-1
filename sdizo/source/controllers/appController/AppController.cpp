#include "stdafx.h"
#include "AppController.h"
#include "../../views/app/appMenu.h"

#include "../arrayController/ArrayController.h"
#include "../listController/ListController.h"
#include "../heapController/HeapController.h"
#include "../bstController/BSTController.h"
#include "../rbTreeController/rbTreeController.h"

using namespace std;

AppController::AppController() : GenericController()
{
	setlocale(LC_ALL, "Polish");
}

void AppController::parseInput(const std::string &input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	switch (parsedInput) 
	{
		case 0:
			this->Stop();
			break;
		case 1:
			controller = std::make_unique<ArrayController>();
			controller->Run();
			break;
		case 2:
			controller = std::make_unique<ListController>();
			controller->Run();
			break;
		case 3:
			controller = std::make_unique<HeapController>();
			controller->Run();
			break;
		case 4:
			controller = std::make_unique<BSTController>();
			controller->Run();
			break;
		case 5:
			controller = std::make_unique<rbTreeController>();
			controller->Run();
			break;
		default:
			throw new std::invalid_argument("Unknown controller input");
			break;
	}
}

void AppController::printView()
{
	menu->print();
}

void AppController::init()
{
	menu = std::make_unique<appMenu>();
	srand((unsigned int)time(NULL));
}

