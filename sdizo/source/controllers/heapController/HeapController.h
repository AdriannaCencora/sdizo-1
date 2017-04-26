#pragma once
#include "../genericController/GenericController.h"
#include "stdafx.h"
class HeapController :
	public GenericController
{
public:
	virtual ~HeapController() {};
	virtual void parseInput(const std::string &input);
	virtual void init();

protected:
	virtual void deleteFromStructure();
	virtual void addToStructure();
	virtual void findInStructure();
	virtual void generateStructure();
	virtual void testStructure();
	virtual void clearStructure();
};

