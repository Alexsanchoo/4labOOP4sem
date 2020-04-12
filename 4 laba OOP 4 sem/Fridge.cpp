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

istream & operator>>(istream & in, Fridge & obj)
{
	int type;
	in >> obj.name >> obj.manufacturer >> obj.cost >> type >> obj.isNotFrost >> obj.minTemperature;
	obj.type = (TypeDep)type;
	return in;
}

ostream & operator<<(ostream & out, Fridge & obj)
{
	out << obj.name << " " << obj.manufacturer << " " << obj.cost << " " << obj.type << " " << obj.isNotFrost << " " <<
		obj.minTemperature << " ";
	return out;
}