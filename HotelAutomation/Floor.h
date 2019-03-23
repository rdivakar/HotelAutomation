#pragma once
#include <vector>
using namespace std;

#include "Corridor.h"
#include "SubCorridor.h"
#include "MainCorridor.h"
#include <map>

using namespace std;


/*
	Floor class to denote, each floor of a Building.
	Each Building may have multiple floors and each floor may have multiple corridors.
*/

class Floor
{
	//Every floor has at least 1 main and sub corridors
	vector<Corridor*> _corridors;
	int _floorNumber;
	map<CorridorType, int> numOfCorridorMap; //<type -> count>
public:
	Floor(int floorNumber);
	~Floor();
	void addCorridor(Corridor* corridor);
	vector<Corridor*> getCorridors();
	string getFloorName()
	{
		return string("Floor " + to_string(_floorNumber));
	}

	int getNumOfCorridors(CorridorType type);

	int getPowerConsumption();
	void LogFloorState();
};

