#include "stdafx.h"
#include "SensorOutput.h"

/*
	Container class for out from the Sensor
*/

SensorOutput::SensorOutput(int floorNumber, int corridorNumber, MovementState state)
{
	this->_floorNumber = floorNumber;
	this->_corridorNumber = corridorNumber;
	this->_movement = state;
}


SensorOutput::~SensorOutput()
{
}

int SensorOutput::getFloorNumber()
{
	return _floorNumber;
}

int SensorOutput::getCorridorNumber()
{
	return _corridorNumber;
}

MovementState SensorOutput::getMovementState()
{
	return _movement;
}
