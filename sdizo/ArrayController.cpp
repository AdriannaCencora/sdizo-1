#include "stdafx.h"
#include "ArrayController.h"

#include "Array.h"
#include "ArrayMenu.h"

using namespace std;

void ArrayController::parseInput(const std::string &input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	system("cls");
	switch (parsedInput)
	{
		case 0:
			this->Stop();
			break;
		case 1:
			this->loadFromFile();
			break;
		case 2:
			this->deleteFromStructure();
			break;
		case 3:
			this->addToStructure();
			break;
		case 4:
			this->findInStructure();
			break;
		case 5:
			this->generateStructure();
			break;
		case 6:
			//Structure is displayed no matter what after every action
			break;
		case 7:
			this->testStructure();
			break;
		default:
			throw new std::invalid_argument("Unknown controller input");
			break;
	}
	system("cls");
}

void ArrayController::init()
{
	structure = std::make_unique<Array>();
	menu = std::make_unique<ArrayMenu>();
}

void ArrayController::loadFromFile()
{
}

void ArrayController::deleteFromStructure()
{
}

void ArrayController::addToStructure()
{
	int index = 0, value = 0;
	cout << "Podaj indeks: ";
	cin >> index;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	structure->addElement(index, value);
}

void ArrayController::findInStructure()
{
}

void ArrayController::generateStructure()
{
}

void ArrayController::testStructure()
{
}
