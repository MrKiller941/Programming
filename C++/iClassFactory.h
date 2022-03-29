#include  "iUnknown.h"
class iClassFactory
{
    public:
virtual H_RESULT GetClassObject(I_ID, void **pv)=0;
};