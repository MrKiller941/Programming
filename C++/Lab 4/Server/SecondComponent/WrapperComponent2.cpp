#include <iostream>
#include "WrapperComponent2.h"
#include <iomanip>
#include <fstream>
#include <sstream>
int components_count = 0;
char buffer[2048];
using namespace std;
HINSTANCE hhh;

ComponentSecond::ComponentSecond()
{
    FunctionType Co_create_instance;
    hhh = LoadLibrary("manager/build/manager.dll");
    if (!hhh)
    {
        std::cout << "no dll" << std::endl;
    }

    Co_create_instance = (FunctionType)GetProcAddress(hhh, "Co_CreateInstance");
    if (!Co_create_instance)
    {
        std::cout << "no dll func" << std::endl;
    }
    Co_create_instance(clsidServ, iid_IEnter, (void **)&enterMatr);

    enterMatr->QueryInterface(iid_ITandP, (void **)&tAndP);

    components_count++;

    system("pause");
}
int **ComponentSecond::getMatr()
{
    return this->matrix;
}

int ComponentSecond::getN()
{
    return this->n;
}

int ComponentSecond::getM()
{
    return this->m;
}

void ComponentSecond::check()
{

    this->matrix = enterMatr->getMatr();

    this->n = enterMatr->getN();

    this->m = enterMatr->getM();
}

void ComponentSecond::TransposeMatrix()
{
    this->tAndP->TransposeMatrix();
}

void ComponentSecond::EnterMatrix(int n, int m)
{
    this->enterMatr->EnterMatrix(n, m);
}

void ComponentSecond::PrintMatrix()
{
    this->check();
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(15) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void ComponentSecond::additionTMByTwo()
{
    tAndP->TransposeMatrix();
    this->check();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] *= 2;
        }
    }
    this->PrintMatrix();
}

ComponentSecond::~ComponentSecond()
{
    components_count--;
    this->enterMatr->Release();
    this->tAndP->Release();
    cout<<n<<endl;
    for (int i = 0; i < n; i++)
    {
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
}

extern "C" H_RESULT __declspec(dllexport) DLL_GetClassObject(CLS_ID clsid, I_ID IClassFactory_id, void **ppv)
{
    if (clsid == clsidSecond)
    {
        IClassFactory_ *factt = new SecondFactory();
        factt->QueryInterface(IClassFactory_id, ppv);
    }
}

H_RESULT SecondFactory::CreateInstance(I_ID iid, void **ppv)
{
    ComponentSecond *comp = new ComponentSecond();

    comp->QueryInterface(iid, ppv);
}

H_RESULT SecondFactory::QueryInterface(I_ID iid, void **ppv)
{
    if (iid == iid_IUnknown_)
    {
        *ppv = (IClassFactory_ *)this;
    }
    else if (iid == iid_IClassFactory)
    {
        *ppv = (IClassFactory_ *)this;
    }
    else
    {
        *ppv = NULL;
        return E_NOINTERFACE__;
    }
    AddRef();
    return S_OK__;
}

H_RESULT ComponentSecond::QueryInterface(I_ID iid, void **ppv)
{
    if (iid == iid_IUnknown_)
    {
        *ppv = (IUnknown_ *)(IAdditionTranspMatrixByTwo *)this;
    }
    else if (iid == iid_AdditionTM)
    {
        *ppv = (IAdditionTranspMatrixByTwo *)this;
    }
    else if (iid == iid_IEnter)
    {
        *ppv = (IEnterIntMatrix *)this;
    }
    else if (iid == iid_ITandP)
    {
        *ppv = (ITransposeAndPrintAnyMatrix *)this;
    }
    else
    {
        ppv = NULL;
        return E_NOINTERFACE__;
    }
    AddRef();
    return S_OK__;
}

ULONG_ ComponentSecond::AddRef()
{
    this->count++;
    std::cout << "\nOuterComponent object " << this << " added; count:" << this->count << std::endl;
}

ULONG_ ComponentSecond::Release()
{
    this->count--;
    std::cout << "\nOuterComponent object " << this << " released; count:" << this->count << std::endl;
    if (this->count == 0)
    {
        delete this;
    }
}

ULONG_ SecondFactory::AddRef()
{
    this->count++;
    std::cout << "\nFactory object " << this << " added; count:" << this->count << std::endl;
}

ULONG_ SecondFactory::Release()
{
    this->count--;
    std::cout << "\nFactory object " << this << " released; count:" << this->count << std::endl;
    if (this->count == 0)
    {
        delete this;
    }
}
int DelModulePath()
{
    ifstream file_in("manager/MyDll.txt");
    if (!file_in)
    {
        return -1;
    }

    CLS_ID fileCLS_ID;
    string s;
    string filedata = "";

    while (getline(file_in, s))
    {
        istringstream is(s, istringstream::in);
        is >> fileCLS_ID;
        if (fileCLS_ID != clsidSecond)
        {
            filedata += s + "\n";
        }
    }
    file_in.close();
    ofstream file_out("manager/MyDll.txt");
    if (!file_out)
    {
        return -1;
    }
    file_out << filedata;
    file_out.close();

    return 0;
}
int SetModulePath()
{
    DelModulePath();
    ofstream file("manager/MyDll.txt", ios_base::app);
    if (!file)
    {
        return -1;
    }
    file << clsidSecond << " " << buffer;
    file.close();
    return 0;
}
extern "C" STDAPI __declspec(dllexport) DllRegisterServer()
{
    if (SetModulePath() == 0)
    {
        return S_OK;
    }
    else
    {
        return S_FALSE;
    }
}
extern "C" STDAPI __declspec(dllexport) DllUnregisterServer()
{
    if (DelModulePath() == 0)
    {
        return S_OK;
    }
    else
    {
        return S_FALSE;
    }
}
extern "C" STDAPI __declspec(dllexport) DllCanUnloadNow()
{
    if (components_count == 0)
    {
        return S_OK;
    }
    else
    {
        return S_FALSE;
    }
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    GetModuleFileName(hinstDLL, buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // attach to process
        // return FALSE to fail DLL load
        break;

    case DLL_PROCESS_DETACH:
        // detach from process
        break;

    case DLL_THREAD_ATTACH:
        // attach to thread
        break;

    case DLL_THREAD_DETACH:
        // detach from thread
        break;
    }
    return TRUE; // succesful
}