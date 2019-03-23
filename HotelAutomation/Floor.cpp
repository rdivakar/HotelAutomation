#include "stdafx.h"
#include "Floor.h"

/*
	Floor class to denote, each floor of a Building. 
	Each Building may have multiple floors and each floor may have multiple corridors.	
*/

Floor::Floor(int floorNumber)
{
	this->_floorNumber = floorNumber;
}

Floor::~Floor()
{
	for (Corridor* cor : _corridors)
	{
		delete cor;
	}
}

void Floor::addCorridor(Corridor * corridor)
{
	numOfCorridorMap[corridor->getCorridorTypeVal()]++;
	_corridors.push_back(corridor);
}

vector<Corridor*> Floor::getCorridors()
{
	return _corridors;
}

int Floor::getNumOfCorridors(CorridorType type)
{
	if (numOfCorridorMap.find(type) != numOfCorridorMap.end())
	{
		return numOfCorridorMap[type];
	}
	return 0;
}

int Floor::getPowerConsumption()
{
	int sum = 0;
	//Get power consumption of each corridor
	for (Corridor* corridor : _corridors)
	{
		sum += corridor->getPowerConsumption();
	}

	return sum;
}

void Floor::LogFloorState()
{
	Config::DefaultOutStream() << " " <<getFloorName() << endl;
	for (Corridor* corridor : getCorridors())
	{
		corridor->LogCorridorState();
	}
}
