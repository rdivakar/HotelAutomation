#pragma once

#include "Building.h"
#include "SensorOutput.h"

/*
	Abstract Rule class that defines the business logic or criteria that the controller needs to apply on the building's power consumption.
*/

class ControllerRule
{
public:
	ControllerRule();
	virtual ~ControllerRule();
	//Function that defines the initial state of the building. To be impletemented based on the rules.
	virtual void SetInitialState(Building* building) = 0;
	//Function that defines the Power management rule. To be impleted by derived classes as needed.
	virtual void ProcessSensorOutput(Building* building,SensorOutput*) = 0;

protected:
	virtual int GetMaxThreshold(Building* building) = 0;
};

