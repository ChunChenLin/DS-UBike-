//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeHeapIMP.h"
#include <algorithm>
#include <iostream>
using namespace std;

//DO SOMETHINE HERE
void UBikeHeapIMP::addUBikePtr(UBike* ubptr){
	(*this)[++ number] = ubptr;

	int p = number;
	ubptr->heapIndex = p;

	while(p > 1){
		if((*this)[p/2]->mileage < (*this)[p]->mileage){
			(*this)[p/2]->heapIndex = ubptr->heapIndex;
			ubptr->heapIndex = p/2;

			UBike* tmp = (*this)[p/2];
			(*this)[p/2] = (*this)[p];
			(*this)[p] = tmp;

			p /= 2;
		}
		else break;
	}
}

UBike* UBikeHeapIMP::removeUBikePtr(int heapIndex){
	UBike *rt = (*this)[heapIndex];

	if(heapIndex == number){
		(*this)[number --] = NULL;
		return rt;
	}
	(*this)[number]->heapIndex = heapIndex;
	(*this)[heapIndex] = (*this)[number];
	(*this)[number --] = NULL;
	
	int p=heapIndex;

	while(true){
		if(p == 1) break;
		int c = p/2;
		if((*this)[c]->mileage < (*this)[p]->mileage){
			(*this)[c]->heapIndex = p;
			(*this)[p]->heapIndex = c;

			UBike* tmp = (*this)[c];
			(*this)[c] = (*this)[p];
			(*this)[p] = tmp;
			p = c;
		}
		else break;
	}

	while(true){
		int pl = p*2, pr = p*2+1;
		int c;
		if(pr<=number){
			if((*this)[pl]->mileage < (*this)[pr]->mileage) c = pr;
			else c = pl;
		}
		else if(pl <= number) c = pl;
		else break;
		if((*this)[c]->mileage > (*this)[p]->mileage){
			(*this)[c]->heapIndex = p;
			(*this)[p]->heapIndex = c;

			UBike* tmp = (*this)[c];
			(*this)[c] = (*this)[p];
			(*this)[p] = tmp;
			
			p = c;
		}
		else break; 
	}

	return rt;
}

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************
