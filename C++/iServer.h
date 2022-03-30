#pragma once
#include "iUnknown.h"

class iServer : public iUnknown
{
public:
    virtual void Func() = 0;
};

class iServer2 : public iUnknown
{
public:
    virtual void Func2() = 0;
};
