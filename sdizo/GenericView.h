#pragma once

#include "stdafx.h"

class GenericView
{
    public:
		virtual ~GenericView() {};
        virtual void print() = 0;
        virtual std::string getOutput() = 0;
};

