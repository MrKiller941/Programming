#include "ComplexNumbers.h"
class ComplexNum: IAddComplexNum, IGetComplexNum, ISetComplexNum, ISubComplexNum {
    private:
        int countReference = 0;
        int n, k;
    public:
        ComplexNum();
        ComplexNum(int n, int k);
        H_RESULT QueryInterface(I_ID iid, void** ppv);
        U_LONG AddRef();
        U_LONG Release();
        ComplexNum add(ComplexNum, ComplexNum);
        ComplexNum sub(ComplexNum, ComplexNum);
        void setComplexNum();
        void getComplexNum();
};
