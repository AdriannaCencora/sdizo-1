#pragma once
#include "../genericController/GenericController.h"
#include "stdafx.h"
class ArrayController :
	public GenericController
{
public:
	virtual ~ArrayController() {};
	virtual void parseInput(const std::string &input);
	virtual void init();

private:
	virtual void deleteFromStructure();
	virtual void addToStructure();
	virtual void findInStructure();
	virtual void generateStructure();
	virtual void testStructure();
	virtual void clearStructure();
};

