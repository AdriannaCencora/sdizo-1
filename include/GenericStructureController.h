#ifndef GENERICSTRUCTURECONTROLLER_H
#define GENERICSTRUCTURECONTROLLER_H

#include <string>
#include <memory>

#include "GenericStructure.h"

class GenericStructureController
{
    public:
        GenericStructureController();
        virtual ~GenericStructureController();
        virtual void parseInput(std::string input) = 0;
        virtual void printView() = 0;

    protected:
        std::unique_ptr<GenericStructure> structure;
};

#endif // GENERICSTRUCTURECONTROLLER_H
