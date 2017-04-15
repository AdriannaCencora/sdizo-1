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
	printNode(string(""), string(""), 0);
}

void Heap::addElement(int value)
{
	int lastIndex = array->getSize();
	array->pushBack(value);
	fixUp();
}

void Heap::removeElement(int value)
{
	int indexFound = -1;
	int lastElementIndex = -1;
	for (int index = 0; index < array->getSize(); ++index)
		if (array->operator[](index) == value)
		{
			indexFound = index;
			lastElementIndex = array->getSize() - 1;	
			break;
		}

	array->swap(indexFound, lastElementIndex);
	array->removeElement(lastElementIndex);
	fixDown(indexFound);
}

void Heap::clearStructure()
{
	array->clearStructure();
}

bool Heap::findValue(int toFind)
{
	return array->findValue(toFind);
}

void Heap::fixUp()
{
	if (array->getSize() < 1)
		return;
	int currNode = array->getSize() - 1;
	int parentNode = (currNode - ((currNode % 2 == 0)? 2:1)) / 2;
	while (currNode != 0)
	{
		if (array->getValue(parentNode) < array->getValue(currNode))
			array->swap(parentNode, currNode);
		currNode = parentNode;
		parentNode = (currNode - ((currNode % 2 == 0) ? 2 : 1)) / 2;
	}
}

void Heap::fixDown(int index)
{
	int leftChild;
	int rightChild;
	bool isLeft, isRight;
	isLeft = isRight = true;
	while (isLeft || isRight)
	{
		isLeft = isRight = true;
		leftChild = index * 2 + 1;
		rightChild = index * 2 + 2;
		
		if (leftChild >= array->getSize() || array->getValue(index) > array->getValue(leftChild))
			isLeft = false;
		else
		{
			array->swap(index, leftChild);
			index = leftChild;	
		}

		if (rightChild >= array->getSize() || array->getValue(index) > array->getValue(rightChild))
			isRight = false;
		else
		{
			array->swap(index, rightChild);
			index = rightChild;
		}
		this->printData();
		system("pause");
	}
}

void Heap::printNode(string& sMiddle, string &sBefore, int currNode)
{
	string s;
	if (currNode < array->getSize())
	{
		s = sMiddle;
		if (sBefore == (string(1, (char)47) + string(1, (char)126)))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)47)) + string(1, (char)126), 2 * currNode + 2);

		s = s.substr(0, sMiddle.length() - 2);

		cout << s << sBefore << (*array)[currNode] << endl;

		s = sMiddle;
		if (sBefore == (string(1, (char)92)) + string(1, (char)126))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)92)) + string(1, (char)126), 2 * currNode + 1);
	}
}
