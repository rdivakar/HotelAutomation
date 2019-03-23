#pragma once
#include <vector>
#include <string>
#include "Floor.h"

/*
	Building is the base class of the physical structure.
	Physical entities like Hotel, Hospital, etc. can be derived from here.
*/

using namespace std;
class Building
{
	string _name;
	vector<Floor*> _floors;
	int _numOfFloors;
public:
	Building();
	virtual ~Building();
	void addFloor(Floor* _floor);
	void setNumOfFloors(int floors);
	int getNumOfFloors() const;
	int getNumOfCorridors(CorridorType type);
	const vector<Floor*>& getFloors();
	void setName(string name);
	string getName() const;
	int getPowerConsumption();
	void LogBuildingState();
};

