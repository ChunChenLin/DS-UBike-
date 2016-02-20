//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "PriceTableIMP.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

//DO SOMETHING HERE
void PriceTableIMP::calcAllPairsShortestPath(std::string mapFile){
	for(int i=0; i < 12; i ++)
		for(int j=0; j < 12; j ++) distTable[StationNames[i]][StationNames[j]] = 9999999;
	for(int i=0; i < 12; i ++) distTable[StationNames[i]][StationNames[i]] = 0;

	ifstream ifs(mapFile);
	string u, v; int x;

	while(ifs >> u >> v >> x){
		distTable[u][v] = min(distTable[u][v], x);
		distTable[v][u] = min(distTable[v][u], x);
	}

	for(int k=0; k < 12; k ++)
		for(int i=0; i < 12; i ++)
			for(int j=0; j < 12; j ++)
				if(distTable[StationNames[i]][StationNames[j]] > distTable[StationNames[i]][StationNames[k]]+distTable[StationNames[k]][StationNames[j]])
					distTable[StationNames[i]][StationNames[j]] = distTable[StationNames[i]][StationNames[k]]+distTable[StationNames[k]][StationNames[j]];
}

int PriceTableIMP::calcPrice(int milageDiff, std::string bClass, std::string from, std::string toStation){
	int d = distTable[from][toStation];
	char c = bClass[0];

	if(d >= milageDiff){
		return milageDiff * (c=='E' ? 30 : 
							 c=='L' ? 25 :
							 c=='R' ? 15 : 20);
	}
	else{
		return milageDiff * (c=='E' ? 40 : 
							 c=='L' ? 30 :
							 c=='R' ? 20 : 25);
	}
}

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************
