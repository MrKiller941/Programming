typedef int H_RESULT; //синоним int
typedef int I_ID; //cиноним int
typedef int CLS_ID; //cиноним int
typedef int U_LONG; //cиноним int

const H_RESULT S_OK = 1111;
const H_RESULT E_NOINTERFACE = -3;
const H_RESULT E_OUTOFMEMORY = -2;
const H_RESULT E_CLASSNOTAVAILABLE = -1;

class iUnknown {
    public:
        virtual H_RESULT QueryInterface(I_ID iid, void** ppv) = 0;
        virtual U_LONG AddRef() = 0;
        virtual U_LONG Release() = 0;
};

class IClassFactory : public iUnknown {
    private:
        int countReference = 0;
    public:
        virtual H_RESULT CreateInstance(I_ID iid, void** ppv) = 0;
        U_LONG AddRef();
        U_LONG Release();
};