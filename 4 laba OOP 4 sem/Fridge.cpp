#include "Fridge.h"

void Fridge::setIsNotFrost(bool frost)
{
	isNotFrost = frost;
}

void Fridge::setMinTemp(double temp)
{
	minTemperature = temp;
}

bool Fridge::getIsNotFrost()
{
	return isNotFrost;
}

double Fridge::getMinTemp()
{
	return minTemperature;
}
