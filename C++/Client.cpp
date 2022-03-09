#include <iostream>
#include "Serv.h"

using namespace std;
int main()
{   iServ* ppv;
    CLS_ID clsid = 1;
    I_ID iid = 1;
    if(CreateInstance(clsid, iid, (void**)&ppv) != 0)
    {
        cout << "Error, Try again...";
        return 0;
    }
    ppv->Func();
}
