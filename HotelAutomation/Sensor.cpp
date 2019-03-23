#include "stdafx.h"
#include "Sensor.h"
#include <regex>

/*
	Senor class passes on the movement information to controller
*/

//Regex to parse input from the Sensor
string Sensor::regExInputMovement = "Movement[\\s]+in[\\s]+Floor[\\s]+([\\d]+),[\\s]+Sub[\\s]corridor[\\s]+(\\d+)";
string Sensor::regExInputNoMovement = "No[\\s]+movement[\\s]+in[\\s]+Floor[\\s]([0-9])+,[\\s]+Sub corridor[\\s]+([0-9])+[\\s]+for[\\s]+a[\\s]+minute";

using namespace std;

Sensor::Sensor()
{
}


Sensor::~Sensor()
{
}

SensorOutput* Sensor::ParseSensorInput(string inputStr)
{
	std::regex movement(regExInputMovement.c_str());
	std::regex noMovement(regExInputNoMovement.c_str());
	
	std::smatch match;
	try
	{
		if (std::regex_match(inputStr, match, movement))
		{
			if (stoi(match[1]) < 1 || stoi(match[2]) < 1)
				return NULL;

			return new SensorOutput(stoi(match[1]), stoi(match[2]), MOVEMENT);
		}
		else if (std::regex_match(inputStr, match, noMovement))
		{

			if (stoi(match[1]) < 1 || stoi(match[2]) < 1)
				return NULL;

			return new SensorOutput(stoi(match[1]), stoi(match[2]), NO_MOVEMENT);
		}
	}
	catch (std::regex_error& ex)
	{
		Config::DefaultOutStream() << ex.what() << endl;
	}
	
	return NULL;
}
