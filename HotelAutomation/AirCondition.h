#pragma once
#include "Equipment.h"
class AirCondition :
	public Equipment
{
	
public:
	AirCondition();
	virtual ~AirCondition();
	string getEquipmentType();
	EquipmentType getEquipmentTypeVal();
};

