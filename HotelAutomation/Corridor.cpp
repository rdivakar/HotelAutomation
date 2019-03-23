#include "stdafx.h"
#include "Corridor.h"

/*
	Base class of all types Corridors, Corridors are the containers of Equipments.
*/


Corridor::Corridor()
{
	corridorNumber = 0;
}

Corridor::~Corridor()
{
	for (Equipment* equip : _equipments)
	{
		delete equip;
	}
}

void Corridor::setCorridorNumber(int number)
{
	corridorNumber = number;
}

int Corridor::getCorridorNumber()
{
	return corridorNumber;
}


void Corridor::addEquipments(Equipment* _equip)
{
	_equipments.push_back(_equip);
}

vector<Equipment*> Corridor::getEquipments()
{
	return _equipments;
}

int Corridor::getPowerConsumption()
{
	int sum = 0;
	//get power consumption of each equipment
	for (Equipment* equip : _equipments)
	{
		sum += equip->getPowerConsumption();
	}
	return sum;
}

string Corridor::getCorridorName()
{
	//get name as its needed for Display
	return getCorridorType() + " " + to_string(corridorNumber);
}

void Corridor::powerOnEquipment(EquipmentType type)
{
	setEquipmentPower(type, POWER_ON);
}

void Corridor::powerOffEquipment(EquipmentType type)
{
	setEquipmentPower(type, POWER_OFF);
}


void Corridor::setEquipmentPower(EquipmentType type, PowerState power)
{
	for (Equipment *equip : getEquipments())
	{
		if (equip->getEquipmentTypeVal() == type && equip->getPowerStateVal() != power)
		{
			equip->setPower(power);
			break;
		}
	}
}


void Corridor::LogCorridorState()
{
	Config::DefaultOutStream() << "  " <<getCorridorName() << endl;
	//Print each equipment information
	for (Equipment* equip : getEquipments())
	{
		equip->LogEquipmentState();
	}
}

