#pragma once
#include "GenericStructure.h"

#include "Array.h"

class Heap :
	public GenericStructure
{
public:
	Heap();
	Heap(int size);
	virtual ~Heap() {};

	virtual void printData();
	virtual void addElement(int value);
	virtual void removeElement(int value);
	virtual void clearStructure();
	virtual bool findValue(int toFind);

private:
	virtual void fixUp();
	virtual void fixDown(int index);


protected:
	std::unique_ptr<Array> array;
	void printNode(std::string &sMiddle, std::string &sBefore, int currNode);
};

