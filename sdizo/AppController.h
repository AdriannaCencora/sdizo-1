#pragma once
#include "GenericController.h"
#include "NotImplementedException.h"

class AppController :
	public GenericController
{
	public:
		AppController();
		virtual ~AppController() {};
		virtual void parseInput(const std::string &input);
		virtual void printView();
		virtual void loadFromFile() { throw new NotImplementedException; };

		virtual void init();	
	private:
		std::unique_ptr<GenericController> controller;
};

