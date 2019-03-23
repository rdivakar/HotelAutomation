#pragma once

/*
	Container class for out from the Sensor
*/


enum MovementState
{
	INVALID = 0,
	MOVEMENT = 1,
	NO_MOVEMENT
};

class SensorOutput
{
	int _floorNumber;
	int _corridorNumber;
	MovementState _movement;

public:
	SensorOutput(int floorNumber, int corridorNumber, MovementState state);
	~SensorOutput();

	int getFloorNumber();
	int getCorridorNumber();
	MovementState getMovementState();

};

