#include "stdafx.h"
#include "HeapController.h"

#include "Heap.h"
#include "heapMenu.h"

using namespace std;

void HeapController::parseInput(const std::string &input)
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
		throw std::invalid_argument("Unknown controller input");
		break;
	}
	system("cls");
}

void HeapController::init()
{
	structure = std::make_unique<Heap>();
	menu = std::make_unique<heapMenu>();
	srand((unsigned int)time(NULL));
}

void HeapController::loadFromFile()
{
	string userInput = "";
	int currentData;
	cout << "Podaj nazwê pliku: ";
	cin >> userInput;
	structure->clearStructure();
	ifstream fileStream(userInput);
	while (fileStream >> currentData)
		structure->addElement(currentData);
}

void HeapController::deleteFromStructure()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	structure->removeElement(value);
}

void HeapController::addToStructure()
{
	int value = 0;

	cout << "Podaj wartoœæ: ";
	cin >> value;
	structure->addElement(value);

}

void HeapController::findInStructure()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	if (structure->findValue(value))
		cout << "Ta wartoœæ zosta³a znaleziona w kopcu!\n";
	else
		cout << "Ta wartoœæ nie zosta³a znaleziona w kopcu!\n";
	system("pause");
}

void HeapController::generateStructure()
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

void HeapController::testStructure()
{
}

void HeapController::clearStructure()
{
	structure->clearStructure();
}