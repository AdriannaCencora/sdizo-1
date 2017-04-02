#include "Array.h"

#include <exception>

#include "ArrayMenu.h"
#include "ArrayView.h"

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

Array::~Array()
{
}

std::unique_ptr<GenericView>  Array::getMenu()
{
    return std::make_unique<ArrayMenu>();
}
std::unique_ptr<GenericView> Array::getStructureView()
{
    return std::make_unique<ArrayView>();
}

void Array::addElement(int value)
{
    if(currSize + 1 >= allocatedSize)
        realocateByStep();
    data[currSize++] = value;
}
void Array::addElement(int index, int value)
{
    if(index > allocatedSize-1)
    {
        realocate(index+1);
        currSize = index+1;
    }
    else if(index <= currSize)
    {
        moveElementsRight(index);
        currSize++;
    }
    else
    {
        currSize = index+1;
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
    if(newStep > 0)
        realocationStep = newStep;
    else
        throw new std::invalid_argument("Value cannot be smaller than 0.");
}

void Array::realocate(int newSize)
{
    std::unique_ptr<int[]> newData = std::make_unique<int[]>(newSize);
    int moveDataToIndex = (newSize > allocatedSize)? allocatedSize : newSize;
    for(int index = 0; index < moveDataToIndex; index++)
        newData[index] = data[index];
    data = std::move(newData);
    allocatedSize = newSize;
}

void Array::realocateByStep()
{
    std::unique_ptr<int[]> newData = std::make_unique<int[]>(allocatedSize + realocationStep);
    for(int index = 0; index < currSize; index++)
        newData[index] = data[index];
    data = std::move(newData);
    allocatedSize = allocatedSize + realocationStep;
}

int Array::getSize()
{
    return allocatedSize;
}

void Array::moveElementsRight(int index)
{
    realocate(allocatedSize + 1);
    for(int i = currSize-1; i >= index; i--)
        data[i+1] = data[i];
}

void Array::moveElementsLeft(int index)
{
    for(int i = index; i < currSize; i--)
        data[i] = data[i+1];
    realocate(allocatedSize-1);
}
