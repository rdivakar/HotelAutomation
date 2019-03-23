#include "stdafx.h"
#include "Light.h"


Light::Light(int number)
{
	setEquipmentNumber(number);
}


Light::~Light()
{
}

EquipmentType Light::getEquipmentTypeVal()
{
	return LIGHT_EQUIPMENT;
}

string Light::getEquipmentType()
{
	return LIGHT_EQUIPMENT_STR;
}