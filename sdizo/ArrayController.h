#pragma once
#include "GenericController.h"
class ArrayController :
	public GenericController
{
public:
	virtual ~ArrayController() {};
	virtual void parseInput(const std::string &input);
	virtual void init();
};

