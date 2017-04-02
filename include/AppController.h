#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "GenericStructureController.h"

#include <memory>

class AppController : public GenericStructureController
{
    public:
        AppController();
        virtual ~AppController();
        virtual void parseInput(std::string input);
        virtual void printView();

    private:
        std::unique_ptr<GenericStructureController> controller;

        void createArrayAction();
};

#endif // APPCONTROLLER_H
