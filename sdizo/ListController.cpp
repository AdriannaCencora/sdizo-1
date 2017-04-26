#include "stdafx.h"
#include "ListController.h"

#include "List.h"
#include "listMenu.h"

using namespace std;

void ListController::parseInput(const std::string &input)
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

void ListController::init()
{
	structure = std::make_unique<List>();
	menu = std::make_unique<listMenu>();
}


void ListController::deleteFromStructure()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	structure->removeElement(value);
}

void ListController::addToStructure()
{
	int index = 0, value = 0, parsedInput = -1;
	string input = "";

	cout << "p - dodaj na pocz¹tku" << endl;
	cout << "k - dodaj na koñcu" << endl;
	cout << "i - dodaj w œrodku" << endl;
	cout << "Twój wybór: ";
	cin >> input;


	switch (input.c_str()[0])
	{
		case 'p':
			addAtBeginning();
			break;
		case 'k':
			addAtEnd();
			break;
		case 'i':
			cout << "Podaj indeks: ";
			cin >> index;
			cout << "Podaj wartoœæ: ";
			cin >> value;
			structure->addElement(index, value);
			break;
		default:
			throw std::invalid_argument("Unknown action input");
	}
}

void ListController::addAtEnd()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	structure->pushBack(value);
}

void ListController::addAtBeginning()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	structure->pushFront(value);
}

void ListController::findInStructure()
{
	int value = 0;
	cout << "Podaj wartoœæ: ";
	cin >> value;
	if (structure->findValue(value))
		cout << "Ta wartoœæ zosta³a znaleziona w liœcie!\n";
	else
		cout << "Ta wartoœæ nie zosta³a znaleziona w liœcie!\n";
	system("pause");
}

void ListController::generateStructure()
{
	int min, max, amount;
	cout << "Podaj minimaln¹ wartoœæ: ";
	cin >> min;
	cout << "Podaj maksymaln¹ wartoœæ: ";
	cin >> max;
	cout << "Podaj iloœæ: ";
	cin >> amount;

	for (int i = 0; i < amount; ++i)
		structure->pushBack(rand() % max + min);
}

void ListController::testStructure()
{
}

void ListController::clearStructure()
{
	structure->clearStructure();
}