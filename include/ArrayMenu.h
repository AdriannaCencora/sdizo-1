#ifndef ARRAYMENU_H
#define ARRAYMENU_H

#include <GenericView.h>


class ArrayMenu : public GenericView
{
    public:
        ArrayMenu();
        virtual ~ArrayMenu();
        virtual void print();
        virtual std::string getOutput();

};

#endif // ARRAYMENU_H
