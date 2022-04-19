#include "iServer.h"

void trace(const char *msg);

class Component : public IEnterIntMatrix, public ITransposeAndPrintAnyMatrix
{
private:
    int count = 0;
    int **matrix;
    int n, m;
    void NewMemoryForIntMatrix();
    void DelMemoryForIntMatrix();

public:
    void EnterMatrix();
    void TransposeMatrix();
    void PrintMatrix();
    ~Component();
    H_RESULT QueryInterface(I_ID iid, void **ppv);
    void AddRef();
    void Release();
};

class Factory : public IClassFactory_
{
private:
    int count = 0;

public:
    H_RESULT QueryInterface(I_ID iid, void **ppv);
    H_RESULT CreateInstance(I_ID iid, void **ppv);
    void AddRef();
    void Release();
    ~Factory();
};

H_RESULT GetClassObject(CLS_ID serv, I_ID IClassFactory_id, void **ppv);