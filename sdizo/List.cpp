#include "stdafx.h"
#include "List.h"

using namespace std;

void List::printData()
{
	if (head == nullptr || tail == nullptr) 
	{
		cout << "Lista jest pusta" << endl;
		return;
	}
	
	Node* tmp = head.get;

	while (tmp->next != nullptr)
	{
		cout << tmp->data << " ";
	}
	cout << endl;

	Node* tmp = tail.get;

	while (tmp->prev != nullptr)
	{
		cout << tmp->data << " ";
	}
}

void List::addElement(int value)
{
}

void List::addElement(int index, int value)
{
}

void List::removeElement(int index)
{
}

void List::clearStructure()
{
}

bool List::findValue(int toFind)
{
	return false;
}
