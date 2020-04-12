#include "Shop.h"

void Shop::setName(string name)
{
	this->name = name;
}

string Shop::getName()
{
	return name;
}

Department & Shop::getHouseholdDep()
{
	return household;
}

Department & Shop::getComputerDep()
{
	return computer;
}
