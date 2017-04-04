#pragma once
#include "GenericController.h"
class AppController :
	public GenericController
{
	public:
		AppController();
		virtual ~AppController() {};
		virtual void parseInput(const std::string &input);
		virtual void printView();
		virtual void run();
		virtual bool isRunning();

		virtual void initialize();	
	private:
		std::unique_ptr<GenericController> controller;
		bool running;
};

