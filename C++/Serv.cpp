#include <iostream>
#include "iFace.h"

class Serv : public iServ, public iServ2
{
private:
    int countReference = 0;
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(I_ID iid, void** ppv);
    U_LONG AddRef();
    U_LONG Release();
    ~Serv();
};

class Serv2 : public iServ, public iServ2
{
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(I_ID iid, void** ppv);
};

Serv::~Serv()
{
    std::cout << "Delete server" << std::endl;
}

void Serv::Func()
{
    std::cout << "Server 1 Interface 1" << std::endl;
}

void Serv::Func2()
{
    std::cout << "Server 1 Interface 2" << std::endl;
}

U_LONG Serv::AddRef() 
{
    countReference++;
    std::cout << "Add reference: " << countReference << std::endl;
    return countReference;
}

U_LONG Serv::Release() 
{
    countReference--;
    std::cout << "Delete reference: " << countReference << std::endl;
    if(countReference == 0)
    {
        delete this;
    }
    return countReference;
}

H_RESULT Serv::QueryInterface(I_ID iid, void** ppv)
{
    switch (iid)
    {
        case IID_iUnknown:
        {
            *ppv = (iUnknown*) (iServ*) this;
            break;
        }
        case IID_iServ:
        {
            *ppv = (iServ*) this;
            break;
        }
        case IID_iServ2:
        {
            *ppv = (iServ2*) this;
            break;
        }
        default:
        {
            *ppv = NULL;
            return E_NOINTERFACE;
        }
    }
    AddRef();
    return S_OK;
}

H_RESULT IServerFactory::CreateInstance(I_ID iid, void** ppv)
{
    Serv* serv = new Serv();
    if (serv == 0)
    {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = serv->QueryInterface(iid, ppv);
    return res;
}

H_RESULT IServerFactory::QueryInterface(I_ID iid, void** ppv)
{
    if (iid == IID_iUnknown || iid == IID_iClassFactory)
    {
        *ppv = (iClassFactory*) this;
    }
    else
    {
        *ppv = 0;
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv)
{
    if(clsid != CLSIDServ)
    {
        return E_CLASSNOTAVAILABLE;
    }
    iServFactory* factory = new IServFactory();
    if(factory == 0) 
    {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = factory->QueryInterface(iid, ppv);
    return res;
}