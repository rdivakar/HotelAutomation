#pragma once
#include "Corridor.h"
class SubCorridor :
	public Corridor
{
public:
	SubCorridor(int number);
	virtual ~SubCorridor();
	string getCorridorType();
	CorridorType getCorridorTypeVal();
};

