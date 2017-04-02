#ifndef ARRAYCONTROLLER_H
#define ARRAYCONTROLLER_H

#include "GenericStructureController.h"

class ArrayController : public GenericStructureController
{
    public:
        ArrayController();
        virtual ~ArrayController();
        virtual void parseInput(std::string input);
        virtual void printView();
};

#endif // ARRAYCONTROLLER_H
