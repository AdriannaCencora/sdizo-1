#ifndef GENERICVIEW_H
#define GENERICVIEW_H

#include <string>

class GenericView
{
    public:
        virtual ~GenericView();
        virtual void print() = 0;
        virtual std::string getOutput() = 0;
};

#endif // GENERICVIEW_H
