#include "stdafx.h"
#include "Array.h"

#include "ArrayMenu.h"

Array::Array() :
	data(std::make_unique<int[]>(1))
	, allocatedSize(1)
{
	isCheap = true;
}

Array::Array(int size) :
	data(std::make_unique<int[]>(size))
{
	allocatedSize = size;
	isCheap = false;
}

void Array::printData()
{
	if (!isEmpty())
		for (int index = 0; index < this->currSize; index++) 
			std::cout << data[index] << ' ';
	else
		std::cout << "Tablica jest pusta!";
	std::cout << std::endl;
}

void Array::addElement(int index, int value)
{
	if (index > currSize - 1)
		throw std::invalid_argument("Indeks poza zasiêgiem tablicy");
	moveElementsRight(index);
	data[index] = value;
}

void Array::pushBack(int value)
{
	if (currSize + 1 > allocatedSize)
		realocate(allocatedSize + 1);
	data[currSize++] = value;
}

void Array::removeElement(int index)
{
	moveElementsLeft(index);
	if (isCheap)
		realocate(allocatedSize - 1);
}
void Array::clearStructure()
{
	data.reset();
	data = std::make_unique<int[]>(1);
	currSize = 0;
	allocatedSize = 1;
}

void Array::realocate(int newSize)
{
	std::unique_ptr<int[]> newData = std::make_unique<int[]>(newSize);
	int moveDataToIndex = (newSize > currSize) ? currSize : newSize;
	for (int index = 0; index < moveDataToIndex; index++)
		newData[index] = data[index];
	data = std::move(newData);
	allocatedSize = newSize;
	currSize = moveDataToIndex;
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
	realocate(allocatedSize * 2);
}

int Array::getSize()
{
	return currSize;
}

bool Array::isEmpty()
{
	return (currSize == 0);
}

void Array::moveElementsRight(int index)
{
	if(allocatedSize < currSize + 1)
		realocate(allocatedSize + 1);
	for (int i = currSize + 1; i >= index; --i)
		data[i] = data[i-1];
	++currSize;
}

void Array::moveElementsLeft(int index)
{
	for (int i = index; i < currSize-1; ++i)
		data[i] = data[i + 1];
	--currSize;
}