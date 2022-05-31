typedef int H_RESULT; // синоним к типу Int
typedef int I_ID;  //синоним к типу Int
typedef int CLS_ID; //синоним к типу Int 
typedef int ULONG_; //синоним к типу Int 
const I_ID iid_IUnknown_ = 0;
const I_ID iid_IServ0 = 1;
const I_ID iid_IServ1 = 2;
const I_ID iid_IClassFactory = 4;
const H_RESULT S_OK = 1000;
const H_RESULT E_NOINTERFACE = -2;
const CLS_ID clsidServ = 11;

class IUnknown_ 
{
  public:
  virtual H_RESULT __stdcall QueryInterface(I_ID iid, void** ppv) = 0;
  virtual ULONG_ AddRef() = 0;
  virtual ULONG_ Release() = 0;
};
