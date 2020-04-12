#include "Keyboard.h"

void Keyboard::setCountKey(int count)
{
	countKey = count;
}

int Keyboard::getCountKey()
{
	return countKey;
}

istream & operator>>(istream & in, Keyboard & obj)
{
	int type;
	in >> obj.name >> obj.manufacturer >> obj.cost >> type >> obj.countKey;
	obj.type = (TypeDep)type;
	return in;
}

ostream & operator<<(ostream & out, Keyboard & obj)
{
	out << obj.name << " " << obj.manufacturer << " " << obj.cost << " " << obj.type << " " << obj.countKey << " ";
	return out;
}
