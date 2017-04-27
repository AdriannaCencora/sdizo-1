#include "stdafx.h"
#include "ArrayController.h"

#include "../../structures/array/Array.h"
#include "../../views/array/ArrayMenu.h"

using namespace std;

void ArrayController::init()
{
	structure = std::make_unique<Array>();
	menu = std::make_unique<ArrayMenu>();
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
	int index = 0, value = 0, parsedInput = -1;
	string input = "";

	cout << "k - dodaj na koñcu" << endl;
	cout << "i - dodaj w œrodku" << endl;
	cout << "Twój wybór: ";
	cin >> input;


	switch (input.c_str()[0])
	{
		case 'k':
			cout << "Podaj wartoœæ: ";
			cin >> value;
			structure->pushBack(value);
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

void ArrayController::testStructure()
{
}
