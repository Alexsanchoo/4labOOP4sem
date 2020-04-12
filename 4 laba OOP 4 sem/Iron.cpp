#include "Iron.h"

void Iron::setMaxTemp(double temp)
{
	maxTemperature = temp;
}

double Iron::getMaxTemp()
{
	return maxTemperature;
}

istream & operator>>(istream & in, Iron & obj)
{
	int type;
	in >> obj.name >> obj.manufacturer >> obj.cost >> type >> obj.maxTemperature;
	obj.type = (TypeDep)type;
	return in;
}

ostream & operator<<(ostream & out, Iron & obj)
{
	out << obj.name << " " << obj.manufacturer << " " << obj.cost << " " << obj.type << " " << obj.maxTemperature << " ";
	return out;
}