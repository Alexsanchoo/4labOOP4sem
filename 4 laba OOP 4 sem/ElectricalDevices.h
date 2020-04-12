#pragma once
#include<string>

using namespace std;

enum TypeGood {
	NONE,
	HOUSEHOLD,
	COMPUTER
};

class ElectricalDevices
{
public:
	ElectricalDevices(string nameSh = "", string manufacturer = "", double costSh = 0.0, TypeGood typeSh = NONE) : 
		name(nameSh), manufacturer(manufacturer), cost(costSh), type(typeSh) {}
	ElectricalDevices(const ElectricalDevices &obj) : name(obj.name), manufacturer(obj.manufacturer), cost(obj.cost), type(obj.type) {}

	void setName(string name);
	void setCost(double cost);
	void setType(TypeGood type);
	void setManufacturer(string manufacturer);
	string getName();
	double getCost();
	TypeGood getType();
	string getManufacturer();

	virtual ~ElectricalDevices() {}

protected:
	string name;
	string manufacturer;
	double cost;
	TypeGood type;
};

