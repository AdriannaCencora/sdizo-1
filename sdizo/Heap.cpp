#include "stdafx.h"
#include "Heap.h"

using namespace std;

Heap::Heap()
{
	array = make_unique<Array>(20);
}

Heap::Heap(int size)
{
	array = make_unique<Array>(size * 2);
}

void Heap::printData()
{
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
