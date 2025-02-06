#include "car.h"


car::car()
{
	
	
	
}

car::car(std::string name, int speed, int control)
{
	name_ = name;
	speed_ = speed;
	control_ = control;
	
}

car::~car()
{
	
	
}

//accessor methods

void car::setName(std::string name)
{
	name_ = name;
}

std::string car::getName()
{
	return name_;
}

void car::setSpeed(int speed)
{
	speed_ = speed;
}

int car::getSpeed()
{
	return speed_;
}

void car::setControl(int control)
{
	control_ = control;
}

int car::getControl()
{
	return control_;
}

void car::setlapNumber(int lapNumber)
{
	lapNumber_ = lapNumber;
}

int car::getlapNumber()
{
	return lapNumber_;
}