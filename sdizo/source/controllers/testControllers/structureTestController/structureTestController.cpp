#include "stdafx.h"
#include "structureTestController.h"
#include "source\structures\array\Array.h"

using namespace std;

structureTestController::structureTestController(GenericStructure * structure, std::string structureName)
{
	m_structure = structure;
	filename = structureName;
	filename.append(".scv");

	// Clearing the file
	std::ofstream ofs;
	ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	saveToFile(structureName);

	srand((unsigned int)time(NULL));
}

void structureTestController::insertionTests()
{
	insertAtBeginning();
	insertAtEnd();
	insertAtRandom();

	cout << "Testy dodawania zako�czone" << endl;
}

void structureTestController::deletionTests()
{
	deleteAtBeginning();
	deleteAtEnd();
	deleteAtRandom();
	cout << "Testy usuwania zako�czone" << endl;
}

void structureTestController::findTests()
{
	findAtBeginning();
	findAtEnd();
	findAtRandom();
	cout << "Testy wyszukiwania zako�czone" << endl;
}

void structureTestController::insertAtBeginning()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Insert at beginning");

	cout << "Test: wstawianie na pocz�tku" << endl;

	for (int testCase = 1; testCase < 6; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i) {
			startTime = chrono::high_resolution_clock::now();
		
			m_structure->addElement(0);

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
		}
		saveToFile(testCase, totalTime);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zako�czono test: wstawianie na pocz�tku" << endl;
}

void structureTestController::insertAtEnd()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Insert at end");

	cout << "Test: wstawianie na ko�cu" << endl;

	for (int testCase = 1; testCase < 6; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i) {
			startTime = chrono::high_resolution_clock::now();

			m_structure->addElement((m_structure->getSize() - 1 <0)? 0 : m_structure->getSize() - 1);

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
		}
		saveToFile(testCase, totalTime);
		totalTime = 0;
		m_structure->clearStructure();

	}

	cout << "Zako�czono test: wstawianie na ko�cu" << endl;
}

void structureTestController::insertAtRandom()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Insert at random");

	cout << "Test: wstawianie losowe" << endl;

	for (int testCase = 1; testCase < 6; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i) {
			startTime = chrono::high_resolution_clock::now();

			m_structure->addElement((m_structure->getSize() == 0)? 0 : rand() % m_structure->getSize());

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
		}
		saveToFile(testCase, totalTime);
		totalTime = 0;
		m_structure->clearStructure();
	}
	cout << "Zako�czono test: wstawianie losowe" << endl;
}

void structureTestController::deleteAtBeginning()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Delete at beginning");

	cout << "Test: usuwanie na pocz�tku" << endl;

	for (int testCase = 1; testCase < 6; ++testCase)
	{

		cout << "n = " << testCase * 1000 << endl;

		for (int i = testCase * 1000 - 1; i >= 0; --i)
			m_structure->addElement(0, i);

		for (int i = 0; i < testCase * 1000; ++i) 
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->removeElement(i);

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
		}
		saveToFile(testCase, totalTime);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zako�czono test: usuwanie na pocz�tku" << endl;

}



void structureTestController::deleteAtEnd()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Delete at end");

	cout << "Test: usuwanie na ko�cu" << endl;

	for (int testCase = 1; testCase < 6; ++testCase)
	{

		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < testCase * 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->removeElement(i);

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
		}
		saveToFile(testCase, totalTime);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zako�czono test: usuwanie na ko�cu" << endl;

}

void structureTestController::deleteAtRandom()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;
	int deletedIndex;
	Array arr;

	saveToFile("Delete at end");

	cout << "Test: usuwanie losowe" << endl;

	for (int testCase = 1; testCase < 6; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			arr.pushBack(i);

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < testCase * 1000; ++i)
		{
			deletedIndex = rand() % m_structure->getSize();
			startTime = chrono::high_resolution_clock::now();

			
			m_structure->removeElement(arr.getValue(deletedIndex));

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

			arr.removeElement(deletedIndex);
		}
		saveToFile(testCase, totalTime);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zako�czono test: usuwanie losowe" << endl;

}

void structureTestController::findAtBeginning()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Find at beginning");

	cout << "Test: wyszukiwanie na pocz�tku" << endl;

	for (int testCase = 1; testCase < 6; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < testCase * 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->findValue(testCase * 1000 - rand() % 30);

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

		}
		saveToFile(testCase, totalTime);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zako�czono test: wyszukiwanie na pocz�tku" << endl;

}

void structureTestController::findAtEnd()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Find at end");

	cout << "Test: wyszukiwanie na ko�cu" << endl;

	for (int testCase = 1; testCase < 6; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < testCase * 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->findValue(0 + rand() % 30);

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

		}
		saveToFile(testCase, totalTime);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zako�czono test: wyszukiwanie na ko�cu" << endl;

}

void structureTestController::findAtRandom()
{
	chrono::high_resolution_clock::time_point startTime;
	chrono::high_resolution_clock::time_point endTime;

	int totalTime = 0;

	saveToFile("Find at end");

	cout << "Test: wyszukiwanie losowe" << endl;

	for (int testCase = 1; testCase < 6; ++testCase)
	{
		cout << "n = " << testCase * 1000 << endl;

		for (int i = 0; i < testCase * 1000; ++i)
			m_structure->addElement(0, i);

		for (int i = 0; i < testCase * 1000; ++i)
		{
			startTime = chrono::high_resolution_clock::now();

			m_structure->findValue(rand() % m_structure->getSize());

			endTime = chrono::high_resolution_clock::now();
			totalTime += (int)std::chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

		}
		saveToFile(testCase, totalTime);
		totalTime = 0;
		m_structure->clearStructure();
	}

	cout << "Zako�czono test: wyszukiwanie losowe" << endl;

}
