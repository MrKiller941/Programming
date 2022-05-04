typedef int H_RESULT; // синонимы к типу Int
typedef int I_ID; // синонимы к типу Int 
typedef int CLS_ID; // синонимы к типу Int 
typedef int ULONG_; // синонимы к типу Int 
const I_ID iid_IUnknown_ = 0; 
const I_ID iid_IEnter = 1;
const I_ID iid_ITandP = 2;
const I_ID iid_IClassFactory = 5;
const H_RESULT S_OK__ = 1000;
const H_RESULT S_FALSE__ = -1000;
const H_RESULT E_NOINTERFACE__ = -1;
const CLS_ID clsidServ = 12;

class IUnknown_
{
public:
  virtual H_RESULT QueryInterface(I_ID iid, void **ppv) = 0;
  virtual ULONG_ AddRef() = 0;
  virtual ULONG_ Release() = 0;
};
