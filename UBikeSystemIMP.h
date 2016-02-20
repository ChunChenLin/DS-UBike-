//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef UBikeSystemIMP_h
#define UBikeSystemIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "readonly/UBikeSystemADT.h"
using namespace std;

class UBikeSystemIMP : public UBikeSystemADT
{
    //DO SOMETHINE HERE
public:
    void InitDistTable (std::string MapFile);
    void NewBike (std::string classType, std::string license, int mileage, std::string station);
    void JunkIt (std::string license);
    void Rent (std::string classType, std::string station);
    void Return (std::string station, std::string license, int returnMile);
    void Trans (std::string station, std::string license);
    void ShutDown();
};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************
