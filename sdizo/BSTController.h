#pragma once
#include "HeapController.h"
class BSTController :
	public HeapController
{
public:
	virtual ~BSTController() = default;
	virtual void parseInput(const std::string &input);
	virtual void init();

protected:
	virtual void findInStructure();
	virtual void repair();
};

