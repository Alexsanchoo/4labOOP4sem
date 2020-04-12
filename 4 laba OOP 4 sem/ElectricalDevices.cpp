#include "ElectricalDevices.h"
#include "Fridge.h"
#include "Iron.h"
#include "Monitor.h"
#include "Keyboard.h"

void ElectricalDevices::setName(string name)
{
	this->name = name;
}

void ElectricalDevices::setCost(double cost)
{
	this->cost = cost;
}

void ElectricalDevices::setType(TypeDep type)
{
	this->type = type;
}

void ElectricalDevices::setManufacturer(string manufacturer)
{
	this->manufacturer = manufacturer;
}

string ElectricalDevices::getName()
{
	return name;
}

double ElectricalDevices::getCost()
{
	return cost;
}

TypeDep ElectricalDevices::getType()
{
	return type;
}

TypeGood ElectricalDevices::getTypeGood()
{
	if (typeid(*this) == typeid(Fridge))
	{
		return TypeGood::FRIDGE;
	} 
	else if (typeid(*this) == typeid(Iron))
	{
		return TypeGood::IRON;
	}
	else if (typeid(*this) == typeid(Monitor))
	{
		return TypeGood::MONITOR;
	}
	else if (typeid(*this) == typeid(Keyboard))
	{
		return TypeGood::KEYBOARD;
	}
	
}

string ElectricalDevices::getManufacturer()
{
	return manufacturer;
}