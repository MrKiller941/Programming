#include <iostream>
#include "Components.h"

int main()
{
    Server serv;
    Server serv2 = serv;
    std::cout<<&serv<<std::endl;
    std::cout<<&serv2<<std::endl;
    serv.enter();
    serv.tranPrint();
    serv2.enter();
    serv2.tranPrint();
    serv.tranPrint();

    return 0;
}