#include "Shop.h"

Shop::Shop(string nameSh) : name(nameSh), household(Department("������� �����")), computer(Department("������������ �����"))
{
	FileManager::readFile("compDep.txt", computer.getGoods());
	FileManager::readFile("houseDep.txt", household.getGoods());
}

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

Shop::~Shop()
{
	FileManager::writeFile("compDep.txt", computer.getGoods());
	FileManager::writeFile("houseDep.txt", household.getGoods());
}
