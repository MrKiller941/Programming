#include <iostream>
#include "Iface.h"

using namespace std;
int main()
{
    IServerFactory* serverFactory;
    IServer2* iServer;
    H_RESULT res = GetClassObject(CLSIDServ, IID_iClassFactory, (void**)&servFactory);
    if(res != S_OK) return res;
    res = serverFactory->CreateInstance(IID_iServ2, (void**)&iServ);
    if(res != S_OK) return res;
    iServer->Func2();
}