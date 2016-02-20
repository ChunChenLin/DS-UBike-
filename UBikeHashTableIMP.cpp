//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeHashTableIMP.h"
using namespace std;

//DO SOMETHINE HERE

long long hsh(string s){
	long long hs=0, hh=0;
	for(int i=0; i < 5; i ++){
		hs *= 31;
		char c = s[i];
		if(c>='0'&&c<='9') hs += c-'0';
		else hs += (c-'A')+10;
	}

	for(int i=10; i < 18; i ++) hh += (1<<(i-10)) * (1&(hs>>i));

	return (int)hh;
}

void UBikeHashTableIMP::addUBikePtr(UBike* ubptr){
	int hh = hsh(ubptr->license);
	
	(*this)[hh].push_back(ubptr);
}

UBike* UBikeHashTableIMP::findUBikePtr(std::string license, bool toRemove){
	int hh = hsh(license);
	UBikePtrList::iterator it;
	UBike* rt = NULL;
	
	for(it = (*this)[hh].begin(); it != (*this)[hh].end(); it ++)
		if((*it)->license == license){
			rt = (*it);
			if(toRemove == true) (*this)[hh].erase(it);
			break ;
		}

	return rt;
}
//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************
