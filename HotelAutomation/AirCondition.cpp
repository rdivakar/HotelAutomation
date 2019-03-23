#include "stdafx.h"
#include "AirCondition.h"


AirCondition::AirCondition()
{
	
}


AirCondition::~AirCondition()
{
}

EquipmentType AirCondition::getEquipmentTypeVal()
{
	return AC_EQUIPMENT;
}


string AirCondition::getEquipmentType()
{
	return AC_EQUIPMENT_STR;
}