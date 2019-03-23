#include "stdafx.h"
#include "HotelBuilder.h"
#include "Config.h"
#include "Hotel.h"
#include "Building.h"
#include "AirCondition.h"
#include "Light.h"
#include "HotelRule.h"

/*
	Static builder class for building custom Hotel.
*/

using namespace std;

Building* HotelBuilder::BuildSimpleHotel()
{
	Logger *log = Logger::GetLoggerInstance();
	
	int numOfFloors = 2;
	int numOfMainCorridorsPerFloor = 1;
	int numOfSubCorridorsPerFloor = 2;

	Config::DefaultOutStream() << "Number of floors :";
	Config::DefaultInStream() >> numOfFloors;
	Config::DefaultOutStream() << "Main corridors per floor :";
	Config::DefaultInStream() >> numOfMainCorridorsPerFloor;
	Config::DefaultOutStream() << "Sub corridors per floor :";
	Config::DefaultInStream() >> numOfSubCorridorsPerFloor;

	Building *newHotel = new Hotel();
	newHotel->setName("Sahaj");
	newHotel->setNumOfFloors(numOfFloors);

	log->Log("Building the Hotel [%s].", newHotel->getName().c_str());

	for (int f = 0; f < numOfFloors; f++)
	{
		
		Floor *floor = new Floor(f + 1);
		log->Log("Constructing Floor [%s].", floor->getFloorName().c_str());

		int equiNum = 1;
		for (int mc = 0; mc < numOfMainCorridorsPerFloor; mc++)
		{
			Corridor *corridor = new MainCorridor(mc + 1);
			log->Log("Adding Main Corridor [%s] to Floor [%s].", corridor->getCorridorName().c_str(), floor->getFloorName().c_str());

			Equipment *equip1 = new Light(equiNum++);
			equip1->setPowerConsumption(5);
			log->Log("Adding Equipment [%s] to Corridor [%s] on Floor [%s].", equip1->toString().c_str(), corridor->getCorridorName().c_str(), floor->getFloorName().c_str());

			corridor->addEquipments(equip1);

			Equipment *equip = new AirCondition();
			equip->setPowerConsumption(10);
			log->Log("Adding Equipment [%s] to Corridor [%s] on Floor [%s].", equip->toString().c_str(), corridor->getCorridorName().c_str(), floor->getFloorName().c_str());

			corridor->addEquipments(equip);

			floor->addCorridor(corridor);
			log->Log("Completed Main Corridor [%s] to Floor [%s].", corridor->getCorridorName().c_str(), floor->getFloorName().c_str());
		}

		equiNum = 1;

		for (int sc = 0; sc < numOfSubCorridorsPerFloor; sc++)
		{
			Corridor *corridor = new SubCorridor(sc + 1);

			log->Log("Adding Sub Corridor [%s] to Floor [%s].", corridor->getCorridorName().c_str(), floor->getFloorName().c_str());

			Equipment *equip1 = new Light(equiNum++);
			equip1->setPowerConsumption(5);
			log->Log("Adding Equipment [%s] to Corridor [%s] on Floor [%s].", equip1->toString().c_str(), corridor->getCorridorName().c_str(), floor->getFloorName().c_str());

			corridor->addEquipments(equip1);
			
			Equipment *equip = new AirCondition();
			equip->setPowerConsumption(10);
			log->Log("Adding Equipment [%s] to Corridor [%s] on Floor [%s].", equip->toString().c_str(), corridor->getCorridorName().c_str(), floor->getFloorName().c_str());

			corridor->addEquipments(equip);

			floor->addCorridor(corridor);
			log->Log("Completed Main Corridor [%s] to Floor [%s].", corridor->getCorridorName().c_str(), floor->getFloorName().c_str());
		}

		newHotel->addFloor(floor);
		log->Log("Completed Floor [%s].", floor->getFloorName().c_str());
	}

	log->Log("Completed building the Hotel [%s].", newHotel->getName().c_str());

	return newHotel;
}
