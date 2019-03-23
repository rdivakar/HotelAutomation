#pragma once
#include <string>

using namespace std;

class Equipment
{
	bool _isPowerOn;
	int _requiredPower;
	string _name;
	int _equimentNumber;

protected:
	
	string getPowerState();
public:
	Equipment();
	virtual ~Equipment();
	int getPowerConsumption();
	void setPowerConsumption(int power);

	string getEquipmentName();
	void setEquipmentNumber(int number);
	
	void setPower(PowerState power);
	void powerOn();
	void powerOff();

	void LogEquipmentState();

	PowerState getPowerStateVal();

	string toString();

	virtual EquipmentType getEquipmentTypeVal() = 0;
	virtual string getEquipmentType() = 0;
};

