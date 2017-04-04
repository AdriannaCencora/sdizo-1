#pragma once
#include "GenericStructure.h"
class Array :
	public GenericStructure
{
public:
	Array();
	Array(int size);
	virtual ~Array() {};

	virtual void printData();

	virtual void addElement(int value);
	virtual void addElement(int index, int value);
	virtual void removeElement(int index);
	virtual void clearStructure();
	virtual void realocate(int newSize);
	virtual bool findValue(int toFind);

	void setValue(int index, int value);
	int getValue(int index);
	void setRealocationStep(int newStep);
	int getRealocationStep();
	int getSize();

	bool isEmpty();

private:
	std::unique_ptr<int[]> data;
	int currSize = 0;
	int allocatedSize = 0;
	int realocationStep = 1;

	void moveElementsRight(int index);
	void moveElementsLeft(int index);
protected:
	virtual void realocateByStep();
};

