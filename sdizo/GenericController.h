#pragma once

#include "stdafx.h"
#include "GenericStructure.h"

class GenericController
{
public:
	virtual ~GenericController() {};
	virtual void parseInput(std::string input) = 0;
	virtual void printView();

protected:
	std::unique_ptr<GenericStructure> structure;
};

