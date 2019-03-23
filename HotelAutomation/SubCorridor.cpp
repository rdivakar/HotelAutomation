#include "stdafx.h"
#include "SubCorridor.h"


SubCorridor::SubCorridor(int number)
{
	setCorridorNumber(number);
}


SubCorridor::~SubCorridor()
{
}

string SubCorridor::getCorridorType()
{
	return SUB_CORRIDOR_STR;
}

CorridorType SubCorridor::getCorridorTypeVal()
{
	return SUB_CORRIDOR;
}
