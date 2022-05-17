#include <iostream>
#include "../manager/manager.h"

typedef H_RESULT (*FunctionType)(CLS_ID, I_ID, void **);
void trace(const char *msg);

//Обертка
class Server
{
private:
    IEnterIntMatrix *enterMatr = NULL;
    ITransposeAndPrintAnyMatrix *TandP = NULL;
    IAdditionTranspMatrixByTwo *TM = NULL;

public:
    Server();
    Server(const Server &other);
    ~Server();
    void enter();
    void tranPrint();
    void additionByTwo();
    // Server &operator=(const Server &other);
};
