#pragma once

#include "Hotel.h"
#include "ControllerRule.h"
#include "Sensor.h"


/*

	Main controller class that manages the Power consumption of the building.
	This is a singleton class as only one control can be present.

*/

class PowerController
{

	Building *_building; //Assuming One hotel per controller. 
	ControllerRule *_controllerRule;
	Sensor *_sensor;

	PowerController();
	~PowerController();
	static PowerController * _controllerIntance;

	SensorOutput* ReadSensor(string sensorInput);

public:
	static PowerController * GetPowerController();

	void SetBuilding(Building* building)
	{
		this->_building = building;
	}
	Building* GetBuilding()
	{
		return _building;
	}
	void SetRule(ControllerRule *rule);
	void SetSensor(Sensor *sensor);
	Sensor* GetSensor();
	void InitializeController();
	
	void BuildingState();

	int StartController();

};

