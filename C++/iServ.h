
#include "iUnknown.h"

class iServ : public iUnknown
{
public:
    virtual void Func() = 0;
};

class iServ2 : public iUnknown
{
public:
    virtual void Func2() = 0;
};
