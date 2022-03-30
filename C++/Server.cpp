#include "Server.h"
#include <iostream>

void Server::Func()
{
    std::cout << "Server 1 Interface 1" << std::endl;
}

void Server::Func2()
{
    std::cout << "Server 1 Interface 2" << std::endl;
}

H_RESULT Server::QueryInterface(I_ID iid, void** ppv)
{
    switch (iid)
    {
        case 0:
        {
            *ppv = (iUnknown*) (IServer*) this;
            return 0;
        }
        case 1:
        {
            *ppv = (IServer*) this;
            return 1;
        }
        case 2:
        {
            *ppv = (IServer2*) this;
            return 2;
        }
        default:
        {
            *ppv = NULL;
            return -1;
        }
    }
}

void Server2::Func()
{
    std::cout << "Server 2 Interface 1" << std::endl;
}

void Server2::Func2()
{
    std::cout << "Server 2 Interface 2" << std::endl;
}

H_RESULT Server2::QueryInterface(I_ID iid, void** ppv)
{
    switch (iid)
    {
        case 0:
        {
            *ppv = (iUnknown*) (IServer*) this;
            return 0;
        }
        case 1:
        {
            *ppv = (IServer*) this;
            return 1;
        }
        case 2:
        {
            *ppv = (IServer2*) this;
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
    iUnknown* server;
    switch (clsid)
    {
        case 1:
        {
            server = (iUnknown*) (IServer*) new Server();
            break;
        }
        case 2:
        {
            server = (iUnknown*) (IServer2*) new Server2();
            break;
        }
        default:
        {
            return 1;
        }
    }
    if(server->QueryInterface(iid, ppv) == -1) return 2;
    return 0;
}