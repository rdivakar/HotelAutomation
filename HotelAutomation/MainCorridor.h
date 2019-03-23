#pragma once
#include "Corridor.h"
class MainCorridor :
	public Corridor
{
public:
	MainCorridor(int number);
	virtual ~MainCorridor();
	string getCorridorType();
	CorridorType getCorridorTypeVal();
};

