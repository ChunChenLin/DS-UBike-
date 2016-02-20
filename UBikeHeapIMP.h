//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef UBikeHeapIMP_h
#define UBikeHeapIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "readonly/UBikeHeapADT.h"

class UBikeHeapIMP : public UBikeHeapADT
{
    //DO SOMETHINE HERE
public:
    void addUBikePtr(UBike* ubptr);
    UBike* removeUBikePtr(int heapIndex);
};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************
