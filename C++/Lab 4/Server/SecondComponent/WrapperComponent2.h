#include <iostream>
#include "../FirstComponent/IServer.h"
#include <windows.h>

typedef H_RESULT (*FunctionType)(CLS_ID, I_ID, void **);

class ComponentSecond : public IAdditionTranspMatrixByTwo, ITransposeAndPrintAnyMatrix, IEnterIntMatrix
{
private:
    int count = 0;
    int **matrix = NULL;
    int n = 0, m = 0;
    IEnterIntMatrix *enterMatr = NULL;
    ITransposeAndPrintAnyMatrix *tAndP = NULL;
    IClassFactory_ *fact = NULL;
    IAdditionTranspMatrixByTwo *tM = NULL;
public:
    void additionTMByTwo();
    void check();
    void TransposeMatrix();
    void PrintMatrix();
    void EnterMatrix(int n, int m);
    int **getMatr();
    int getN();
    int getM();
    ComponentSecond();
    ~ComponentSecond();
    H_RESULT QueryInterface(I_ID iid, void **ppv);
    ULONG_ AddRef();
    ULONG_ Release();
};

class SecondFactory : public IClassFactory_
{
private:
    int count = 0;

public:
    H_RESULT QueryInterface(I_ID iid, void **ppv);
    H_RESULT CreateInstance(I_ID iid, void **ppv);
    ULONG_ AddRef();
    ULONG_ Release();
};