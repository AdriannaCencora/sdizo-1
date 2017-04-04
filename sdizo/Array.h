#pragma once
#include "GenericStructure.h"
class Array :
	public GenericStructure
{
public:
	Array();
	Array(int size);
	virtual ~Array() {};

	virtual std::unique_ptr<GenericView> getMenu();
	virtual std::unique_ptr<GenericView> printStructureData();

	virtual void addElement(int value);
	virtual void addElement(int index, int value);
	virtual void removeElement(int index);
	virtual void clearStructure();
	virtual void realocate(int newSize);

	void setValue(int index, int value);
	int getValue(int index);
	void setRealocationStep(int newStep);
	int getRealocationStep();
	int getSize();

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

