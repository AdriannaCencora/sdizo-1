#ifndef APPMENU_H
#define APPMENU_H

#include <GenericView.h>


class appMenu : public GenericView
{
    public:
        appMenu();
        virtual ~appMenu();
        virtual void print();
        virtual std::string getOutput();
};

#endif // APPMENU_H
