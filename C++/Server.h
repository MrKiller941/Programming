#include "iServer.h"

class Server : public iServer, public iServer2
{
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(int iid, void** ppv);
};

class Server2 :public iServer, public iServer2
{
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(int iid, void** ppv);
};

H_RESULT CreateInstance(CLS_ID clsid, I_ID iid, void** ppv);
