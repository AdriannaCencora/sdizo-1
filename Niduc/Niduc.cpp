// Niduc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "App.h"

using namespace std;

int main(int args, char** argv)
{
	if (args != 3)
	{
		cout << "Nieprawid³owa liczba argumentów!" << endl;
		system("pause");
		return 0;
	}

	App app(argv[1], argv[2]);

	cout << "Starting reading the file..." << endl;
	app.readInputFile();
	cout << "File read!" << endl;
	app.generateErrorMask();
	cout << "Mask error generated!" << endl;
	app.applyErrors();
	cout << "Errors applied!" << endl;
	app.writeToOutputFile();
	cout << "Wrote to file!" << endl;


    return 0;
}

