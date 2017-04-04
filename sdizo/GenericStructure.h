#pragma once

#include "stdafx.h"
#include "GenericView.h"

class GenericStructure
{
public:
	virtual ~GenericStructure() {};

	virtual void addElement(int value) = 0;
	virtual void addElement(int index, int value) = 0;
	virtual void removeElement(int value) = 0;
	virtual void clearStructure() = 0;
	virtual bool findValue(int toFind) = 0;
	virtual void printData() = 0;
};

