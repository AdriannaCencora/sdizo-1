#include "stdafx.h"
#include "Array.h"

#include "ArrayMenu.h"

Array::Array() :
	data(std::make_unique<int[]>(1))
{
	allocatedSize = 1;
}

Array::Array(int size) :
	data(std::make_unique<int[]>(size))
{
	allocatedSize = size;
}

void Array::printData()
{
	if (!isEmpty())
		for (int index = 0; index < this->currSize; index++) 
		{
			std::cout << '[' << index << '] ' << data[index];
			if (index % 15 == 0 && index != 0)
				std::cout << std::endl;
			else 
				std::cout << ' ';
		}
	else
		std::cout << "Tablica jest pusta!";
	std::cout << std::endl;
}

void Array::addElement(int value)
{
	if (currSize + 1 > allocatedSize)
		realocateByStep();
	data[currSize++] = value;
}
void Array::addElement(int index, int value)
{
	if (index > allocatedSize - 1)
	{
		realocate(index + 1);
		currSize = index + 1;
	}
	else if (index <= currSize)
	{
		moveElementsRight(index);
	}
	else
	{
		currSize = index + 1;
	}
	data[index] = value;
}

void Array::removeElement(int index)
{
	moveElementsLeft(index);
}
void Array::clearStructure()
{
	data.reset();
	data = std::make_unique<int[]>(1);
	currSize = 0;
	allocatedSize = 1;
}

int Array::getRealocationStep()
{
	return realocationStep;
}

void Array::setRealocationStep(int newStep)
{
	if (newStep > 0)
		realocationStep = newStep;
	else
		throw new std::invalid_argument("Value cannot be smaller than 0.");
}

void Array::realocate(int newSize)
{
	std::unique_ptr<int[]> newData = std::make_unique<int[]>(newSize);
	int moveDataToIndex = (newSize > allocatedSize) ? allocatedSize : newSize;
	for (int index = 0; index < moveDataToIndex; index++)
		newData[index] = data[index];
	data = std::move(newData);
	allocatedSize = newSize;
}

bool Array::findValue(int toFind)
{
	for (int index = 0; index < currSize; index++)
		if (data[index] == toFind)
			return true;
	return false;
}

void Array::realocateByStep()
{
	std::unique_ptr<int[]> newData = std::make_unique<int[]>(allocatedSize + realocationStep);
	for (int index = 0; index < currSize; index++)
		newData[index] = data[index];
	data = std::move(newData);
	allocatedSize = allocatedSize + realocationStep;
}

int Array::getSize()
{
	return allocatedSize;
}

bool Array::isEmpty()
{
	return (currSize == 0);
}

void Array::moveElementsRight(int index)
{
	realocate(allocatedSize + 1);
	for (int i = currSize - 1; i >= index; --i)
		data[i] = data[i-1];
	++currSize;
}

void Array::moveElementsLeft(int index)
{
	for (int i = index; i < currSize-1; ++i)
		data[i] = data[i + 1];
	realocate(allocatedSize - 1);
	--currSize;
}