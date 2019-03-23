// HotelAutomation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"
#include "PowerController.h"
#include "Hotel.h"
#include "Building.h"
#include "AirCondition.h"
#include "Light.h"
#include "HotelRule.h"
#include "HotelBuilder.h"

/*
	Main function
*/


int main(int argc, char *argv[])
{
	bool custOutStream = false, custInStream = false;
	if (argc > 1) //For Unit testing
	{
		for (int i = 1; i < argc; i++)
		{
			if (!strcmp(argv[i], "-in"))
				custInStream = true;
			else if (!strcmp(argv[i], "-out"))
				custOutStream = true;
		}
	}

	Config::Intialize(custOutStream, custInStream);

	Logger *log = Logger::GetLoggerInstance();
	log->Log("Initializing Power Controller.");
	log->Log("custOutStream = [%d] custInStream = [%d].", custOutStream, custInStream);

	Config::DefaultOutStream() << endl;

	PowerController *powerController = PowerController::GetPowerController();
	Building *hotel = HotelBuilder::BuildSimpleHotel();

	powerController->SetBuilding(hotel);
	powerController->SetRule(new HotelRule());
	powerController->SetSensor(new Sensor());
	powerController->InitializeController();
	log->Log("Printing Initial Building state on output.");
	powerController->BuildingState();
	log->Log("Starting Power Controller.");
	powerController->StartController();
	log->Log("Power Controller stopped.");

	Config::CleanUp();
    return 0;
}

