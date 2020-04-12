#pragma once
#include<string>
#include "Department.h"
#include "FileManager.h"

using namespace std;

class Shop
{
public:
	Shop(string nameSh = "");
	Shop(const Shop &obj) : name(obj.name), household(obj.household), computer(obj.computer) {}
	void setName(string name);
	string getName();
	Department& getHouseholdDep();
	Department& getComputerDep();
	~Shop();

private:
	string name;
	Department household;
	Department computer;
};

