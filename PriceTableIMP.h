//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef PriceTableIMP_h
#define PriceTableIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "readonly/PriceTableADT.h"

class PriceTableIMP : public PriceTableADT
{
    //DO SOMETHING HERE
public:
    void calcAllPairsShortestPath(std::string mapFile);
    int calcPrice(int milageDiff, std::string bClass, std::string from, std::string toStation);
};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************