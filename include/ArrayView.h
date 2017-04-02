#ifndef ARRAYVIEW_H
#define ARRAYVIEW_H

#include <GenericView.h>


class ArrayView : public GenericView
{
    public:
        ArrayView();
        virtual ~ArrayView();

        virtual void print();
        virtual std::string getOutput();
};

#endif // ARRAYVIEW_H
