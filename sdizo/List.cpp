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
	shared_ptr<Node> newNode = make_shared<Node>(value);
	
	if (!isEmpty()) 
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
	if (isEmpty())
		addElement(value);
	shared_ptr<Node> newNode = make_shared<Node>(index);
	shared_ptr<Node> currNode = getNodePtr(index);
	if (currNode != nullptr)
	{
		if (currNode->prev == nullptr)
			head = newNode;
		if (currNode->next == nullptr)
			tail = newNode;
		currNode->prev->next = newNode;
		currNode->prev = newNode;
		newNode->next = currNode;
	}
	else
		throw invalid_argument("Indeks poza zakresem");
}

void List::removeElement(int index)
{
	shared_ptr<Node> toDelete = getNodePtr(index);
	if (toDelete == nullptr)
		throw new invalid_argument("Nieprawid³owy indeks");

	if (toDelete->prev == nullptr)
		head = toDelete->next;
	else
		toDelete->prev->next = toDelete->next;
	
	if (toDelete->next == nullptr)
		tail = toDelete->prev;
	else
		toDelete->next->prev = toDelete->prev;
	
	toDelete->prev.reset();
	toDelete->next.reset();
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

shared_ptr<List::Node> List::getNodePtr(int index)
{
	if (isEmpty)
		return nullptr;

	shared_ptr<Node> currNode = head;
	for (int i = 0; i < index && currNode != nullptr; ++i)
		currNode = currNode->next;

	return currNode;
}