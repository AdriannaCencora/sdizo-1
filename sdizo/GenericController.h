#pragma once

#include "stdafx.h"
#include "GenericStructure.h"

class GenericController
{
public:
	GenericController();
	virtual ~GenericController() {};
	virtual void parseInput(const std::string &input) = 0;
	virtual void printView();
	virtual void loadFromFile();
	bool isRunning();
	void Run();
	void Stop();

protected:
	std::unique_ptr<GenericStructure> structure;
	std::unique_ptr<GenericView> menu;

	virtual void init();

private:
	bool running;

};

