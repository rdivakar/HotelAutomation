#pragma once
#include "ControllerRule.h"


/*
	Hotel spcific rule class that defines the business logic or criteria that the controller needs to apply on the building's power consumption.
*/

class HotelRule :
	public ControllerRule
{
	int GetMaxThreshold(Building * building);

	void optimizePowerConsumption(Building * building);
	void powerOnPendingACs(Building * building);

public:
	HotelRule();
	virtual ~HotelRule();
	//defines the initial state of the Hotel
	void SetInitialState(Building* building);
	//Has the logic to control the equipments
	void ProcessSensorOutput(Building * building, SensorOutput *);
};

