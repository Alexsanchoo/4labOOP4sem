#include "ElectricalDevices.h"

void ElectricalDevices::setName(string name)
{
	this->name = name;
}

void ElectricalDevices::setCost(double cost)
{
	this->cost = cost;
}

void ElectricalDevices::setType(TypeGood type)
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

TypeGood ElectricalDevices::getType()
{
	return type;
}

string ElectricalDevices::getManufacturer()
{
	return manufacturer;
}

