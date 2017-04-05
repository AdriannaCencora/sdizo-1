#include "stdafx.h"
#include "List.h"

using namespace std;

void List::printData()
{
	if (!isEmpty()) 
	{
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
	else 
		cout << "Lista jest pusta" << endl;
}

void List::addElement(int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(5);
	
	if (isEmpty()) 
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else 
	{
		tail = newNode;
		head = newNode;
	}
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

bool List::isEmpty()
{
	if (head == nullptr || tail == nullptr)
		return true;
	return false;
}
