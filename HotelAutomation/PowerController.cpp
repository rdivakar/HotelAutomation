#include "stdafx.h"
#include "PowerController.h"

/*
	
	Main controller class that manages the Power consumption of the building. 
	This is a singleton class as only one control can be present.

*/

PowerController* PowerController::_controllerIntance = NULL;

PowerController::PowerController()
{
	_building = NULL;
	_controllerRule = NULL;
}

PowerController::~PowerController()
{
	if(_building)
		delete _building;
	if (_controllerRule)
		delete _controllerRule;
}

PowerController * PowerController::GetPowerController()
{
	//Singleton class, as there can be only one controller. 
	//Considering single thread application, not making synchronization fixes.
	if (_controllerIntance == NULL)
		_controllerIntance = new PowerController();

	return _controllerIntance;
}

void PowerController::SetRule(ControllerRule *rule)
{
	if (_controllerRule)
		delete _controllerRule; //Free if already initialized

	_controllerRule = rule;
}

void PowerController::SetSensor(Sensor * sensor)
{
	if (_sensor)
		delete _sensor; //Free if already initialized

	_sensor = sensor;
}

Sensor* PowerController::GetSensor()
{
	return _sensor;
}

void PowerController::InitializeController()
{
	if(_building) //if building is initialized, then apply the rule on the building.
		_controllerRule->SetInitialState(_building); 
}

void PowerController::BuildingState()
{
	if(_building)
		_building->LogBuildingState();
}

SensorOutput* PowerController::ReadSensor(string sensorInput)
{
	if (GetSensor())
	{
		return GetSensor()->ParseSensorInput(sensorInput);
	}
	return NULL;
}

int PowerController::StartController()
{
	Logger *log = Logger::GetLoggerInstance();

	/*
		Here is where the controller gets all the inputs, be it from User or Sensor or Clock(If power management is needed in day time)
	*/

	while (1)
	{
		char buffer[4096] = "";
		try
		{
			//Config::DefaultOutStream() << "Waiting on input.." << endl;
			if (Config::DefaultInStream().getline(buffer, sizeof buffer))
			{
				string input(buffer);
				SensorOutput *sensorCmd = NULL;
				
				log->Log("Received input [%s]",input.c_str());

				if (input == STOP_COMMAND)
				{
					Config::DefaultOutStream() << "Controller stopped." << endl;
					delete sensorCmd;
					return 1;
				}
				/*	
					Pass the input to the Sensor to understand it.
					Receiving of input from Sensor could be part of Sensor class itself.
					But for that application needs to be multi threaded to able to receive both user and sensor input.
					To keep the application simple all inputs are read from single stream and passed to respective class to understand it.
				*/
				else if ((sensorCmd = ReadSensor(input)) != NULL)
				{
					//Debugging purpose
					//Config::DefaultOutStream() << sensorCmd->getFloorNumber() << " " << sensorCmd->getCorridorNumber() << " " << sensorCmd->getMovementState() << endl;
					if (_building)
					{
						//Apply Rule on the building for sensor output
						_controllerRule->ProcessSensorOutput(_building, sensorCmd);
						BuildingState();
					}

				}
				else
				{
					//Config::DefaultOutStream() << "Failed to process input : " << input <<" Try again..." <<endl;
				}
				if(sensorCmd)
					delete sensorCmd;
			}
			else
			{
				Config::DefaultOutStream() << "Input stream error" << _errno << endl;;
				return -1;
			}
		}
		catch (std::exception& e)
		{
			cout << "Exception : " << e.what() << endl;
		}
	}

	return 0;
}

