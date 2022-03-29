#include "iServ.h"
#include "iClassFactory.h"
class Serv : public iServ, public iServ2, public iClassFactory
{
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(int iid, void** ppv);
    H_RESULT GetClassObject(int iid, void** ppv);
};

class Serv2 :public iServ, public iServ2, public iClassFactory
{
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(int iid, void** ppv);
    H_RESULT GetClassObject(int iid, void** ppv);
};

H_RESULT CreateInstance(CLS_ID clsid, I_ID iid, void** ppv);
H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv);
