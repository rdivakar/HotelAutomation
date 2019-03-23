#pragma once


#define __MODULE_NAME_ "HotelAutomation"
#define __LOG_BUFF_SIZE__ 4096

#define STOP_COMMAND "STOP"




//Power values

#define POWER_ON_STR "ON"
#define POWER_OFF_STR "OFF"

enum PowerState
{
	POWER_ON = 1,
	POWER_OFF
};

//Equipment values

#define LIGHT_EQUIPMENT_STR "LIGHT"
#define AC_EQUIPMENT_STR "AC"

enum EquipmentType
{
	LIGHT_EQUIPMENT = 1,
	AC_EQUIPMENT = 2
};

//Corridor values

#define MAIN_CORRIDOR_STR "Main Corridor"
#define SUB_CORRIDOR_STR "Sub Corridor"

enum CorridorType
{
	MAIN_CORRIDOR = 1,
	SUB_CORRIDOR
};


