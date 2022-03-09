#include "Serv.h"
#include <iostream>

void Serv::Func()
{
    std::cout << "Serv1 Interface 1" << std::endl;
}

void Serv::Func2()
{
    std::cout << "Serv 1 Interface 2" << std::endl;
}

H_RESULT Serv::QueryInterface(I_ID iid, void** ppv)
{
    switch (iid)
    {
        case 0:
        {
            *ppv = (iUnknown*) (iServ*) this;
            return 0;
        }
        case 1:
        {
            *ppv = (iServ*) this;
            return 1;
        }
        case 2:
        {
            *ppv = (iServ2*) this;
            return 2;
        }
        default:
        {
            *ppv = NULL;
            return -1;
        }
    }
}

void Serv2::Func()
{
    std::cout << "Server 2 Interface 1" << std::endl;
}

void Serv2::Func2()
{
    std::cout << "Serv 2 Interface 2" << std::endl;
}

H_RESULT Serv2::QueryInterface(I_ID iid, void** ppv)
{
    switch (iid)
    {
        case 0:
        {
            *ppv = (iUnknown*) (iServ*) this;
            return 0;
        }
        case 1:
        {
            *ppv = (iServ*) this;
            return 1;
        }
        case 2:
        {
            *ppv = (iServ2*) this;
            return 2;
        }
        default:
        {
            *ppv = NULL;
            return -1;
        }
    }
}

H_RESULT CreateInstance(CLS_ID clsid, I_ID iid, void** ppv)
{
    iUnknown* Serv;
    switch (clsid)
    {
        case 1:
        {
            Serv = (iUnknown*) (iServ*) new Serv2();
            break;
        }
        case 2:
        {
            Serv = (iUnknown*) (iServ2*) new Serv2();
            break;
        }
        default:
        {
            return 1;
        }
    }
    if(Serv->QueryInterface(iid, ppv) == -1) return 2;
    return 0;
}
