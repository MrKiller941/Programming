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

class IServerFactory : public iClassFactory 
{
    public:
        IServerFactory() {};
        H_RESULT QueryInterface(I_ID iid, void** ppv);
        H_RESULT CreateInstance(I_ID iid, void** ppv);
};

H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv);