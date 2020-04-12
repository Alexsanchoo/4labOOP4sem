#include "Monitor.h"

void Monitor::setWidth(double width)
{
	this->width = width;
}

void Monitor::setHeight(double height)
{
	this->height = height;
}

double Monitor::getWidth()
{
	return width;
}

double Monitor::getHeight()
{
	return height;
}

istream & operator>>(istream & in, Monitor & obj)
{
	int type;
	in >> obj.name >> obj.manufacturer >> obj.cost >> type >> obj.width >> obj.height;
	obj.type = (TypeDep)type;
	return in;
}

ostream & operator<<(ostream & out, Monitor & obj)
{
	out << obj.name << " " << obj.manufacturer << " " << obj.cost << " " << obj.type << " " << obj.width << " " <<
		obj.height << " ";
	return out;
}
