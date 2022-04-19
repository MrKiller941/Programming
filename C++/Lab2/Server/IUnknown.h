typedef int H_RESULT; // синонимы к int
typedef int I_ID; // синонимы к int
typedef int CLS_ID; // синонимы к int 
typedef int ULONG_; // синонимы к int
const I_ID iid_IUnknown_ = 0;
const I_ID iid_IServ0 = 1;
const I_ID iid_IServ1 = 2;
const I_ID iid_IClassFactory = 5;
const H_RESULT S_OK = 1000;
const H_RESULT E_NOINTERFACE = -1;
const CLS_ID clsidServ = 12;

class IUnknown_
{
public:
  virtual H_RESULT __stdcall QueryInterface(I_ID iid, void **ppv) = 0;
  virtual void AddRef() = 0;
  virtual void Release() = 0;
};