#include "iUnknown.h"
#include "ComplexNum.h"

const I_ID IID_iUnknown = 0;
const I_ID IID_IClassFactory = 10;

const CLS_ID CLSIDComp = 101;

const I_ID IID_IAddComplexNum = 6;
const I_ID IID_ISubComplexNum = 2;
const I_ID IID_IGetCompexNum = 5;
const I_ID IID_ISetCompexNum = 4;

class IAddComplexNum: public iUnknown {
public:
    virtual ComplexNum add(ComplexNum, ComplexNum) = 0;
};

class ISubComplexNum: public iUnknown {
public:
    virtual ComplexNum sub(ComplexNum, ComplexNum) = 0;
};

class IGetComplexNum: public iUnknown {
public:
    virtual void getComplexNum() = 0;
};

class ISetComplexNum: public iUnknown {
public:
    virtual void setComplexNum() = 0;
};

class ComplexNumFactory : public iUnknown
{
    private:
        int countReference = 0;
    public:
        H_RESULT CreateInstance(I_ID iid, void** ppv, int n, int k);
        H_RESULT QueryInterface(I_ID iid, void** ppv);
        U_LONG AddRef();
        U_LONG Release();
        ComplexNumFactory();
};

H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv);

class ComplexNumWrapper
{
    private:
        ComplexNumFactory* factory;

        IAddComplexNum* iAddComplexNum;
        ISubComplexNum* iSubComplexNum;
        IGetComplexNum* iGetComplexNum;
        ISetComplexNum* iSetComplexNum;

    public:
        void setComplexNum();
        void getComplexNum();
        ComplexNum add(ComplexNum n1, ComplexNum n2);
        ComplexNum sub(ComplexNum n1, ComplexNum n2);

        ComplexNumWrapper(int n, int k);
        ~ComplexNumWrapper();
};