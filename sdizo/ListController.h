#pragma once
#include "GenericController.h"
class ListController :
	public GenericController
{
public:
	virtual ~ListController() {};
	virtual void parseInput(const std::string &input);
	virtual void init();

private:
	virtual void loadFromFile();
	virtual void deleteFromStructure();
	virtual void addToStructure();
	virtual void addAtEnd();
	virtual void addAtBeginning();
	virtual void findInStructure();
	virtual void generateStructure();
	virtual void testStructure();
	virtual void clearStructure();
};

