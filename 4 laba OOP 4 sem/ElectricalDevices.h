	#pragma once
#include<iostream>
#include<string>
#include<typeinfo>	

using namespace std;

enum TypeDep {
	NONE,
	HOUSEHOLD,
	COMPUTER
};

enum TypeGood { FRIDGE, IRON, MONITOR, KEYBOARD};


class ElectricalDevices
{
public:
	ElectricalDevices(string nameSh = "", string manufacturer = "", double costSh = 0.0, TypeDep typeSh = NONE) : 
		name(nameSh), manufacturer(manufacturer), cost(costSh), type(typeSh) {}
	ElectricalDevices(const ElectricalDevices &obj) : name(obj.name), manufacturer(obj.manufacturer), cost(obj.cost), type(obj.type) {}

	void setName(string name);
	void setCost(double cost);
	void setType(TypeDep type);
	void setManufacturer(string manufacturer);
	string getName();
	double getCost();
	TypeDep getType();
	string getManufacturer();
	virtual TypeGood getTypeGood();

	virtual ~ElectricalDevices() {}

protected:
	string name;
	string manufacturer;
	double cost;
	TypeDep type;
};

