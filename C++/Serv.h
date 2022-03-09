#include "iServ.h"

class Serv : public iServ, public iServ2
{
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(int iid, void** ppv);
};

class Serv2 :public iServ, public iServ2
{
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(int iid, void** ppv);
};

H_RESULT CreateInstance(CLS_ID clsid, I_ID iid, void** ppv);
