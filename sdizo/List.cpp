#include "stdafx.h"
#include "List.h"

using namespace std;

void List::printData()
{
	if (!isEmpty()) 
	{
		Node* tmp = head.get();

		while (tmp != nullptr)
		{
			cout << tmp->data << " ";
			tmp = tmp->next.get();
		}
		cout << endl;

		tmp = tail.get();

		while (tmp != nullptr)
		{
			cout << tmp->data << " ";
			tmp = tmp->prev.get();
		}
		cout << endl;
	}	
	else 
		cout << "Lista jest pusta" << endl;
}

void List::pushBack(int value)
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

	++size;
}

void List::pushFront(int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(value);

	if (!isEmpty())
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	else
	{
		tail = newNode;
		head = newNode;
	}

	++size;
}

void List::addElement(int index, int value)
{
	shared_ptr<Node> newNode = make_shared<Node>(value);
	shared_ptr<Node> currNode = getNodePtr(index);
	if (currNode != nullptr)
	{
		if (currNode->prev == nullptr)
			head = newNode;
		else
			currNode->prev->next = newNode;
		if (currNode->next == nullptr)
			tail = currNode;
		newNode->prev = currNode->prev;
		currNode->prev = newNode;
		newNode->next = currNode;
	}
	else
		throw invalid_argument("Indeks poza zakresem");
	++size;
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

	--size;
}

void List::clearStructure()
{
}

bool List::findValue(int toFind)
{
	if (isEmpty())
		return false;

	shared_ptr<Node> currNode = head;
	while (currNode != nullptr)
	{
		if (currNode->data == toFind)
			return true;
		currNode = currNode->next;
	}
	return false;
}

bool List::isEmpty()
{
	return size == 0;
}

shared_ptr<List::Node> List::getNodePtr(int index)
{
	if (isEmpty())
		return nullptr;

	shared_ptr<Node> currNode = head;
	for (int i = 0; i < index && currNode != nullptr; ++i)
		currNode = currNode->next;

	return currNode;
}