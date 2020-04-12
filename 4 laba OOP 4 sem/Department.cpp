#include "Department.h"

Department::Department(const Department & obj) : name(obj.name)
{
	for (size_t i = 0; i < obj.goods.size(); i++)
	{
		goods.push_back(obj.goods[i]);
	}
}

void Department::setName(string name)
{
	this->name = name;
}

string Department::getName()
{
	return name;
}

vector<ElectricalDevices*>& Department::getGoods()
{
	return goods;
}

Department::~Department()
{
	for (size_t i = 0; i < goods.size(); i++)
	{
		delete goods[i];
		goods[i] = nullptr;
	}
}
