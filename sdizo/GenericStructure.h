#pragma once

#include "stdafx.h"
#include "GenericView.h"

class GenericStructure
{
public:
	virtual ~GenericStructure() {};

	virtual std::unique_ptr<GenericView> getMenu() = 0;
	virtual std::unique_ptr<GenericView> getStructureView() = 0;

	virtual void addElement(int value) = 0;
	virtual void removeElement(int value) = 0;
	virtual void clearStructure() = 0;
	virtual bool findValue(int toFind) = 0;
};

