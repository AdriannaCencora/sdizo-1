#include "stdafx.h"
#include "genericTestController.h"

using namespace std;

void genericTestController::runAllTests()
{
	insertionTests();
	deletionTests();
	findTests();
}

void genericTestController::saveToFile(int testSize, int time)
{
	file.open(filename, std::ios::out);
	if (file.good())
		file << testSize << "," << time << endl;
	else
	{
		cout << "Test file error occured!" << endl;
		system("pause");
	}
	file.close();
}

void genericTestController::saveToFile(std::string message)
{
	file.open(filename, std::ios::out);
	if (file.good())
		file << message << endl;
	else
	{
		cout << "Test file error occured!" << endl;
		system("pause");
	}
	file.close();
}
