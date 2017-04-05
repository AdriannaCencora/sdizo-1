#pragma once
#include "GenericStructure.h"

class List :
	public GenericStructure
{
public:
	virtual ~List() {};

	virtual void printData();

	virtual void addElement(int value);
	virtual void addElement(int index, int value);
	virtual void removeElement(int index);
	virtual void clearStructure();
	virtual bool findValue(int toFind);

private:
	class Node {
	public:
		std::shared_ptr<Node> next;
		std::shared_ptr<Node> prev;
		int	data;
	};

	std::shared_ptr<Node> head;
	std::shared_ptr<Node> tail;
};

