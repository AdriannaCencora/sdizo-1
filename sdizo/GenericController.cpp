#include "stdafx.h"
#include "GenericController.h"

using namespace std;

GenericController::GenericController() :
	running(false)
{
}

void GenericController::printView()
{
	structure->printData();
	menu->print();
}

void GenericController::Run()
{
	init();
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

void GenericController::Stop()
{
	running = false;
}

void GenericController::init()
{
}

bool GenericController::isRunning()
{
	return running;
}
