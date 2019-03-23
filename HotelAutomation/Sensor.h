#pragma once
#include "SensorOutput.h"

/*
	Senor class passes on the movement information to controller
*/

class Sensor
{
	static string regExInputMovement;
	static string regExInputNoMovement;

public:
	Sensor();
	~Sensor();

	SensorOutput* ParseSensorInput(string inputStr);


};

