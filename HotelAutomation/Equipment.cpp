#include "stdafx.h"
#include "Equipment.h"


void Equipment::setPower(PowerState power)
{
	_isPowerOn = power == POWER_ON ? true : false;
}

Equipment::Equipment()
{
	_isPowerOn = false;
	_requiredPower = 0;
	_equimentNumber = 0;
}


Equipment::~Equipment()
{
}

int Equipment::getPowerConsumption()
{
	if (_isPowerOn)
		return _requiredPower;
	return 0;
}

void Equipment::setPowerConsumption(int power)
{
	_requiredPower = power;
}

string Equipment::getEquipmentName()
{
	return getEquipmentType() + " " + ((_equimentNumber > 0) ? to_string(_equimentNumber) : "");
}

void Equipment::setEquipmentNumber(int number)
{
	_equimentNumber = number;
}

void Equipment::powerOn()
{
	_isPowerOn = true;
}

void Equipment::powerOff()
{
	_isPowerOn = false;
}

void Equipment::LogEquipmentState()
{
	//get name as its needed for Display
	Config::DefaultOutStream() << "   " <<toString() << endl;
}

PowerState Equipment::getPowerStateVal()
{
	if (_isPowerOn)
		return POWER_ON;
	else
		return POWER_OFF;
}

string Equipment::getPowerState()
{
	if (_isPowerOn)
		return POWER_ON_STR;
	else
		return POWER_OFF_STR;
}

string Equipment::toString()
{
	return getEquipmentName() + " : " + getPowerState();
}

