#ifndef GENERICSTRUCTURE_H
#define GENERICSTRUCTURE_H

#include "GenericView.h"
#include <memory>
#include <iostream>

class GenericStructure
{
    public:
        GenericStructure();
        virtual ~GenericStructure();

        virtual std::unique_ptr<GenericView> getMenu() = 0;
        virtual std::unique_ptr<GenericView> getStructureView() = 0;

        virtual void addElement(int) = 0;
        virtual void removeElement(int) = 0;
        virtual void clearStructure() = 0;
        //virtual bool findValue(int toFind);
};

#endif // GENERICSTRUCTURE_H
