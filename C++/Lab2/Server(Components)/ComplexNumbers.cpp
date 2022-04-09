#include "ComplexNumbers.h"
#include "ComplexNum.h"
#include <iostream>


ComplexNum::ComplexNum() {
    n = 0;
    k = 0;
}

ComplexNum::ComplexNum(int n, int k) {
    this->n = n;
    this->k = k;
}

void ComplexNum::setComplexNum(){
    std::cout << "Real number: ";
    std::cin >> n;
    std::cout << "Imaginary number: ";
    std::cin >> k;
}

void ComplexNum::getComplexNum() {
    std::cout << "Complex number: "<< n << "+" << k << "i" << std::endl;
}

ComplexNum ComplexNum::add(ComplexNum n1, ComplexNum n2) {
    ComplexNum result;
    result.n = n1.n + n2.n;
    result.k = n1.k + n2.k;
    return result;
}

ComplexNum ComplexNum::sub(ComplexNum n1, ComplexNum n2) {
    ComplexNum result;
    result.n = n1.n - n2.n;
    result.k = n1.k - n2.k;
    return result;
}

U_LONG ComplexNum::AddRef() 
{
    countReference++;
    return countReference;
}

U_LONG ComplexNum::Release() 
{
    countReference--;
    if(countReference == 0)
    {
        delete this;
    }
    return countReference;
}

H_RESULT ComplexNum::QueryInterface(I_ID iid, void** ppv)
{
    switch (iid)
    {
        case IID_iUnknown:
        {
            *ppv = (iUnknown*) (ISetComplexNum*) this;
            break;
        }
        case IID_IAddComplexNum:
        {
            *ppv = (IAddComplexNum*) this;
            break;
        }
        case IID_ISubComplexNum:
        {
            *ppv = (ISubComplexNum*) this;
            break;
        }
        case IID_ISetCompexNum:
        {
            *ppv = (ISetComplexNum*) this;
            break;
        }
        case IID_IGetCompexNum:
        {
            *ppv = (IGetComplexNum*) this;
            break;
        }
        default:
        {
            *ppv = 0;
            return E_NOINTERFACE;
        }
    }
    AddRef();
    return S_OK;
}

ComplexNumFactory::ComplexNumFactory() {}

U_LONG ComplexNumFactory::AddRef() 
{
    countReference++;
    return countReference;
}

U_LONG ComplexNumFactory::Release() 
{
    countReference--;
    if(countReference == 0)
    {
        delete this;
    }
    return countReference;
}

H_RESULT ComplexNumFactory::CreateInstance(I_ID iid, void** ppv, int n, int k)
{
    ComplexNum* complexNum = new ComplexNum(n, k);
    if (complexNum == 0)
    {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = complexNum->QueryInterface(iid, ppv);
    return res;
}

H_RESULT ComplexNumFactory::QueryInterface(I_ID iid, void** ppv)
{
    if (iid == IID_iUnknown || iid == IID_IClassFactory)
    {
        *ppv = (IClassFactory*) this;
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
    if(clsid != CLSIDComp)
    {
        return E_CLASSNOTAVAILABLE;
    }
    ComplexNumFactory* factory = new ComplexNumFactory();
    if(factory == 0) 
    {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = factory->QueryInterface(iid, ppv);
    return res;
}

ComplexNumWrapper::ComplexNumWrapper(int n, int k)
{
    GetClassObject(CLSIDComp, IID_IClassFactory, (void**)&factory);
    factory->CreateInstance(IID_ISetCompexNum, (void**)&iSetComplexNum, n, k);
    factory->Release();
    iSetComplexNum->QueryInterface(IID_IGetCompexNum, (void**)&iGetComplexNum);
}


ComplexNumWrapper::~ComplexNumWrapper() 
{
    iSetComplexNum->Release();
    iAddComplexNum->Release();
    iGetComplexNum->Release();
    iSubComplexNum->Release();
}

void ComplexNumWrapper::setComplexNum()
{
    iSetComplexNum->setComplexNum();
}

void ComplexNumWrapper::getComplexNum()
{
    iGetComplexNum->getComplexNum();
}

ComplexNum ComplexNumWrapper::sub(ComplexNum n1, ComplexNum n2)
{
    iSubComplexNum->sub(n1, n2);
}


ComplexNum ComplexNumWrapper::add(ComplexNum n1, ComplexNum n2)
{
    iAddComplexNum->add(n1, n2);
}