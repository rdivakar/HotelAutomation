#include "stdafx.h"
#include "MainCorridor.h"


MainCorridor::MainCorridor(int number)
{
	setCorridorNumber(number);
}


MainCorridor::~MainCorridor()
{
}

string MainCorridor::getCorridorType()
{
	return MAIN_CORRIDOR_STR;
}

CorridorType MainCorridor::getCorridorTypeVal()
{
	return MAIN_CORRIDOR;
}
