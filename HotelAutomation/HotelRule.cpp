#include "stdafx.h"
#include "HotelRule.h"


/*
	Hotel spcific rule class that defines the business logic or criteria that the controller needs to apply on the building's power consumption.
*/

HotelRule::HotelRule()
{
	//nothing to do here
}


HotelRule::~HotelRule()
{
	//nothing to do here
}

//Function that defines the initial state of the Hotel.
void HotelRule::SetInitialState(Building * building)
{
	if (building == NULL)
		return;

	/* 
		Note:
			Here we could take the time input and set the state accoridng to the time of the day.
			Since our controller is going run only in night. Not considering the time here.
	*/

	for (Floor* floor : building->getFloors())
	{
		for (Corridor* corridor : floor->getCorridors())
		{
			if (corridor->getCorridorTypeVal() == MAIN_CORRIDOR)
			{
				for (Equipment* equip : corridor->getEquipments())
				{
					equip->powerOn();
				}
			}
			else
			{
				for (Equipment* equip : corridor->getEquipments())
				{
					if (equip->getEquipmentTypeVal() == AC_EQUIPMENT)
						equip->powerOn();
					else
						equip->powerOff();
				}
			}
		}//Corridor
	}//Floor
}

int HotelRule::GetMaxThreshold(Building* building)
{
	return 15 * building->getNumOfCorridors(MAIN_CORRIDOR) + 10 * building->getNumOfCorridors(SUB_CORRIDOR);
}

void HotelRule::optimizePowerConsumption(Building * building)
{
	Logger *log = Logger::GetLoggerInstance();
	for (Floor *floor : building->getFloors())
	{
		if (building->getPowerConsumption() < GetMaxThreshold(building))
			break;

		for (Corridor *corridor : floor->getCorridors())
		{
			if (corridor->getCorridorTypeVal() != SUB_CORRIDOR)
				continue;

			if (building->getPowerConsumption() < GetMaxThreshold(building))
				break;

			for (Equipment *equip : corridor->getEquipments())
			{
				//If Sub corridor AC is powered on, then power it off.
				// Do worry if Sub Corridor is where the movement was detected
				if (equip->getEquipmentTypeVal() == AC_EQUIPMENT && equip->getPowerStateVal() == POWER_ON)
				{
					if (building->getPowerConsumption() > GetMaxThreshold(building))
					{
						log->Log("Powered off light equipment[%s] on corridor [%s]", equip->toString().c_str(), corridor->getCorridorName().c_str());
						equip->powerOff();
						log->Log("Power consumption stats: Build's consumption [%d], max threashold [%d]", building->getPowerConsumption(), GetMaxThreshold(building));
					}
					else
						break;
				}
			}//Equipment
		}//Corridor
	}//Floor

}

void HotelRule::powerOnPendingACs(Building * building)
{
	Logger *log = Logger::GetLoggerInstance();
	for (Floor *floor : building->getFloors())
	{
		for (Corridor *corridor : floor->getCorridors())
		{
			if (corridor->getCorridorTypeVal() != SUB_CORRIDOR)
				continue;

			for (Equipment *equip : corridor->getEquipments())
			{
				if (equip->getEquipmentTypeVal() == AC_EQUIPMENT && equip->getPowerStateVal() == POWER_OFF)
				{
					//If powering on the AC does not cross the threshold. Then power it on. 
					if (building->getPowerConsumption() + equip->getPowerConsumption() < GetMaxThreshold(building))
					{
						log->Log("Powered on light equipment[%s] on corridor [%s]", equip->toString().c_str(), corridor->getCorridorName().c_str());
						equip->powerOn();
						log->Log("Power consumption stats: Build's consumption [%d], max threashold [%d]", building->getPowerConsumption(), GetMaxThreshold(building));
					}
					else
						break;//
				}
			}//Equipment
		}//Corridor
	}//Floor

}

//Criteria how power needs to be controlled in a Hotel. 
void HotelRule::ProcessSensorOutput(Building* building, SensorOutput* sensorOutput)
{
	Logger *log = Logger::GetLoggerInstance();

	int floorNumber = sensorOutput->getFloorNumber();
	int corridorNumer = sensorOutput->getCorridorNumber();
	MovementState movement = sensorOutput->getMovementState();

	/*
		Note:
			We could read the current time here and use it in power management logic.
	*/

	log->Log("Processing sensor input Floor[%d] Corridor[%d] Movement[%d]", floorNumber, corridorNumer, movement);

	Floor *floor = building->getFloors()[floorNumber-1];

	log->Log("Got floor number [%s]", floor->getFloorName().c_str());

	//Lets power on the required equipment
	for (Corridor *corridor : floor->getCorridors())
	{
		if (corridor->getCorridorTypeVal() == SUB_CORRIDOR && corridor->getCorridorNumber() == corridorNumer)
		{
			if (sensorOutput->getMovementState() == MOVEMENT)
			{
				corridor->powerOnEquipment(LIGHT_EQUIPMENT);
				log->Log("Powered on light equipment on corridor [%s]", corridor->getCorridorName().c_str());
			}
			else if (sensorOutput->getMovementState() == NO_MOVEMENT)
			{
				corridor->powerOffEquipment(LIGHT_EQUIPMENT);
				log->Log("Powered off light equipment on corridor [%s]", corridor->getCorridorName().c_str());
			}

			break;
		}
	}

	log->Log("Power consumption stats: Build's consumption [%d], max threashold [%d]", building->getPowerConsumption(), GetMaxThreshold(building));

	//Power off AC on Sub Corridor if power consumption is high
	if (building->getPowerConsumption() > GetMaxThreshold(building))
	{
		log->Log("Trying to power off Sub corridor ACs");
		optimizePowerConsumption(building);
	}
	else
	{
		log->Log("Trying to power on Sub corridor ACs if consumption is low.");
		//Power on AC on Sub Corridor if power consumption is too less
		powerOnPendingACs(building);
	}

	log->Log("Completed processing sensor input Floor[%d] Corridor[%d] Movement[%d]", floorNumber, corridorNumer, movement);
}

