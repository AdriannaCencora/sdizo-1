#pragma once
#include "GenericController.h"
class AppController :
	public GenericController
{
	public:
		virtual ~AppController() {};
		virtual void parseInput(std::string input);
		virtual void printView();

	private:
		std::unique_ptr<GenericController> controller;

		void createArrayAction();
};

