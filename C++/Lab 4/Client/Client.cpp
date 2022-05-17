#include <iostream>
#include <windows.h>
#include "WrapperComponent.h"
using namespace std;


int main()
{
    
    Server serv;
    serv.enter();
    serv.tranPrint();
    serv.additionByTwo();

    system("pause");
    return 0;
}
