#pragma once
#include "../genericController/GenericController.h"

class BSTController :
	public GenericController
{
public:
	virtual ~BSTController() = default;
	virtual void parseInput(const std::string &input);
	virtual void init();

protected:
	virtual void findInStructure();
	virtual void repair();
};

