#include "iUnknown.h"

class IServer : public iUnknown
{
public:
    virtual void Func() = 0;
};

class IServer2 : public iUnknown
{
public:
    virtual void Func2() = 0;
};