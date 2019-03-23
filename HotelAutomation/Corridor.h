#pragma once
#include <vector>
using namespace std;

#include "Equipment.h"

/*
	Base class of all types Corridors, Corridors are the containers of Equipments.
*/


class Corridor
{
	vector<Equipment*> _equipments;
	int corridorNumber;

protected:
	void setEquipmentPower(EquipmentType type, PowerState power);
	
public:
	Corridor();
	virtual ~Corridor();

	void setCorridorNumber(int number);
	int getCorridorNumber();
	void addEquipments(Equipment* _equip);
	vector<Equipment*> getEquipments();

	int getPowerConsumption();
	string getCorridorName();

	void powerOnEquipment(EquipmentType type);

	void powerOffEquipment(EquipmentType type);
	
	void LogCorridorState();

	virtual string getCorridorType() = 0;
	virtual CorridorType getCorridorTypeVal() = 0;
};

