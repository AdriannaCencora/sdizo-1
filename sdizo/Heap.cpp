#include "stdafx.h"
#include "Heap.h"

using namespace std;

Heap::Heap()
{
	array = make_unique<Array>(20);
	for (int i = 0; i < 20; ++i)
		array->pushBack(i);
}

Heap::Heap(int size)
{
	array = make_unique<Array>(size * 2);
}

void Heap::printData()
{
	printNode(string(""), string(""), 0);
}

void Heap::addElement(int value)
{
}

void Heap::removeElement(int value)
{
}

void Heap::clearStructure()
{
}

bool Heap::findValue(int toFind)
{
	return false;
}

void Heap::fixUp()
{
}

void Heap::fixDown()
{
}

void Heap::printNode(string& sMiddle, string &sBefore, int currNode)
{
	string s;
	if (currNode < array->getSize())
	{
		s = sMiddle;
		if (sBefore == (string(1, (char)47) + string(1, (char)45)))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)47)) + string(1, (char)45), 2 * currNode + 2);

		s = s.substr(0, sMiddle.length() - 2);

		cout << s << sBefore << (*array)[currNode] << endl;

		s = sMiddle;
		if (sBefore == (string(1, (char)92)) + string(1, (char)45))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)92)) + string(1, (char)45), 2 * currNode + 1);
	}
}
