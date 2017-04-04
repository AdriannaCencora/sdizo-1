#include "stdafx.h"
#include "AppController.h"
#include "appMenu.h"

#include "ArrayController.h"

using namespace std;

AppController::AppController() :
	running(false)
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
			running = false;
			break;
		case 1:
			controller = std::make_unique<ArrayController>();
			break;
		default:
			throw new std::invalid_argument("Unknown controller input");
		break;
	}
}

void AppController::printView()
{
	appMenu view;
	view.print();
}

void AppController::run()
{
	running = true;
	string userInput;
	do {
		system("cls");
		this->printView();
		cout << "Podaj opcjê: " << endl;
		cin >> userInput;

		try 
		{
			this->parseInput(userInput);
		}
		catch (invalid_argument&) 
		{
			cout << "Nieprawid³owy argument" << endl;
			system("pause");
		}
	} while (this->isRunning());
}

bool AppController::isRunning()
{
	return running;
}

void AppController::initialize()
{
	menu = std::make_unique<appMenu>();
}

