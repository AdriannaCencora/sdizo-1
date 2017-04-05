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
		case 8:
			this->clearStructure();
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
	srand((unsigned int)time(NULL));
}

void ArrayController::loadFromFile()
{
	string userInput = "";
	int currentData;
	cout << "Podaj nazwê pliku: ";
	cin >> userInput;
	ifstream fileStream(userInput);
	while (fileStream >> currentData)
		structure->addElement(currentData);
}

void ArrayController::deleteFromStructure()
{
	int index = 0;
	cout << "Podaj indeks: ";
	cin >> index;
	structure->removeElement(index);
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
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	if (structure->findValue(value))
		cout << "Ta wartoœæ zosta³a znaleziona w tablicy!\n";
	else
		cout << "Ta wartoœæ nie zosta³a znaleziona w tablicy!\n";
	system("pause");
}

void ArrayController::generateStructure()
{
	int min, max, amount;
	cout << "Podaj minimaln¹ wartoœæ: ";
	cin >> min;
	cout << "Podaj maksymaln¹ wartoœæ: ";
	cin >> max;
	cout << "Podaj iloœæ: ";
	cin >> amount;

	for (int i = 0; i < amount; ++i)
		structure->addElement(rand() % max + min);
}

void ArrayController::testStructure()
{
}

void ArrayController::clearStructure()
{
	structure->clearStructure();
}
