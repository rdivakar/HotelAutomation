#include "stdafx.h"
#include "Building.h"
#include "Config.h"

/*
	Building is the base class of the physical structure. 
	Physical entities like Hotel, Hospital, etc. can be derived from here. 
*/

Building::Building()
{
	_name = "";
	_numOfFloors = 0;
}

Building::~Building()
{
	for (Floor* floor : getFloors())
	{
		delete floor;
	}
}


void Building::addFloor(Floor* _floor)
{
	_floors.push_back(_floor);
}

void Building::setNumOfFloors(int floors)
{
	_numOfFloors = floors;
}

int Building::getNumOfFloors() const
{
	return _numOfFloors;
}

int Building::getNumOfCorridors(CorridorType type)
{
	int count = 0;
	for (Floor *floor : getFloors())
	{
		count += floor->getNumOfCorridors(type);
	}
	return count;
}

const vector<Floor*>& Building::getFloors()
{
	return _floors;
}

void Building::setName(string name)
{
	_name = name;
}

string Building::getName() const
{
	return _name;
}

int Building::getPowerConsumption()
{
	int sum = 0;
	//get power consumption of each floor
	for (Floor* floor : getFloors())
	{
		sum += floor->getPowerConsumption();
	}
	return sum;
}

void Building::LogBuildingState()
{
	Config::DefaultOutStream() << getName() << endl;

	for (Floor* floor : getFloors())
	{
		floor->LogFloorState();
	}
}
