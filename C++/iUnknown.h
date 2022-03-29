typedef int H_RESULT; // синонимы для int
typedef int I_ID; // синонимы для int
typedef int CLS_ID; // синонимы для int
typedef int ULONG;
const I_ID IID_Unknown=0;
const I_ID IID_iServ=1;
const I_ID IID_iServ2=2;
const I_ID IID_iClassFactory=5;
const H_RESULT S_OK=1111;
const H_RESULT E_NOINTERFACE=-1;
const H_RESULT E_OUTOFINTERFACE=-2;
const H_RESULT E_CLASSNOTAVAILABLE=-3;
const CLS_ID CLSIDServ=101;
class iUnknown{
 public: 
 virtual H_RESULT QueryInterface(I_ID iid, void**  ppv)=0;  
};
class iClassFactory  : public iUnknown
{
    public:
virtual H_RESULT CreateInstance(I_ID, void** ppv)=0;
};





