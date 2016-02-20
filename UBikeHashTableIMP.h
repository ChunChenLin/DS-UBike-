//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef UBikeHashTableIMP_h
#define UBikeHashTableIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "readonly/UBikeHashTableADT.h"

class UBikeHashTableIMP : public UBikeHashTableADT
{
    //DO SOMETHINE HERE
public:
    void addUBikePtr(UBike* ubptr);
    UBike* findUBikePtr(std::string license, bool toRemove);
};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************
