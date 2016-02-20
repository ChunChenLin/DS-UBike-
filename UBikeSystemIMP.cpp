//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeSystemIMP.h"
using namespace std;

//DO SOMETHINE HERE
void UBikeSystemIMP::InitDistTable (std::string MapFile){
	priceTable.calcAllPairsShortestPath(MapFile);
}

void UBikeSystemIMP::NewBike (std::string classType, std::string license, int mileage, std::string station){
	UBike *cur = new UBike; cur->mileage = mileage; cur->license = license; cur->station = station; cur->classType = classType, cur->isRented = false;
	ubHashTable.addUBikePtr(cur);
	ubStations[station][classType].addUBikePtr(cur);
}

void UBikeSystemIMP::JunkIt (std::string license){
	UBike *cur = ubHashTable.findUBikePtr(license, false);
	if(cur!=NULL && cur->isRented!=true){
        ubHashTable.findUBikePtr(license, true);
		ubStations[cur->station][cur->classType].removeUBikePtr(cur->heapIndex);
		delete cur; cur = NULL;
	}
}

void UBikeSystemIMP::Rent (std::string classType, std::string station){
	if(ubStations[station][classType].isEmpty()) return ;

	UBike *cur = ubStations[station][classType].removeUBikePtr(1);
	ubStations[station]["Rented"].addUBikePtr(cur);
	cur->isRented = true; 
}

void UBikeSystemIMP::Return (std::string station, std::string license, int returnMile){
	UBike *cur = ubHashTable.findUBikePtr(license, false);
	if(cur==NULL) return ;
	if(cur->isRented == false) return ;

	net += priceTable.calcPrice(returnMile-(cur->mileage), cur->classType, cur->station, station);
	ubStations[cur->station]["Rented"].removeUBikePtr(cur->heapIndex);
	cur->mileage = returnMile, cur->isRented = false;
	ubStations[cur->station][cur->classType].addUBikePtr(cur); // ?
}

void UBikeSystemIMP::Trans (std::string station, std::string license){
	UBike *cur = ubHashTable.findUBikePtr(license, false);
	if(cur==NULL || cur->isRented==true) return ;
	ubStations[cur->station][cur->classType].removeUBikePtr(cur->heapIndex);
	ubStations[station][cur->classType].addUBikePtr(cur);
	cur->station = station;
}

void UBikeSystemIMP::ShutDown(){
	for(int i=0; i < 256; i ++) ubHashTable[i].clear();

	for(int i=0; i < 12; i ++)
		for(int j=0; j < 5; j ++){
			int x=ubStations[StationNames[i]][HeapNames[j]].number;
			for(int k=0; k < x; k ++) ubStations[StationNames[i]][HeapNames[j]][k] = NULL;
			ubStations[StationNames[i]][HeapNames[j]].number = 0;
		}
}

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************
