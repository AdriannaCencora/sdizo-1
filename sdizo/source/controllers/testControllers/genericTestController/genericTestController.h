#pragma once

#include "source\structures\genericStructure\GenericStructure.h"
#include "stdafx.h"

class genericTestController
{
public:
	genericTestController() = default;
	virtual ~genericTestController() = default;

	virtual void insertionTests() = 0;
	virtual void deletionTests() = 0;
	virtual void findTests() = 0;
	virtual void runAllTests();

protected:
	virtual void saveToFile(int testSize, int time);
	virtual void saveToFile(std::string message);

	std::string filename;

private:
	std::ofstream file;
	std::unique_ptr<GenericStructure> structure;
};

