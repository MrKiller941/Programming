typedef int H_RESULT; // синонимы для int
typedef int I_ID; // синонимы для int
typedef int CLS_ID; // синонимы для int

class  iUnknown
{
public:
    virtual H_RESULT QueryInterface(I_ID iid, void** ppv) = 0;
};
