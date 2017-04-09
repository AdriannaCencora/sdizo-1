#pragma once

#include "stdafx.h"
#include "GenericView.h"
#include "NotImplementedException.h"

class GenericStructure
{
public:
	virtual ~GenericStructure() {};

	virtual void addElement(int value) { throw NotImplementedException(); };
	virtual void addElement(int index, int value) { throw NotImplementedException(); };
	virtual void pushBack(int value) { throw NotImplementedException(); };
	virtual void pushFront(int value) { throw NotImplementedException(); };
	virtual void removeElement(int value) = 0;
	virtual void clearStructure() = 0;
	virtual bool findValue(int toFind) = 0;
	virtual void printData() = 0;
};

