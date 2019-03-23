#pragma once
#include "Equipment.h"
class Light :
	public Equipment
{
	
public:
	Light(int number);
	virtual ~Light();
	string getEquipmentType();
	EquipmentType getEquipmentTypeVal();
};

