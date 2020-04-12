#pragma once
#include<iostream>
#include<iomanip>
#include<regex>
#include<vector>
#include "ElectricalDevices.h"
#include"Department.h"
#include "ValidValue.h"
#include "Functions.h"
#include"Fridge.h"
#include "Iron.h"
#include"Monitor.h"
#include"Keyboard.h"

using namespace std;

class DepartmentManager
{
public:
	static void addGood(ElectricalDevices *good, Department &obj);
	static int showGoods(Department &obj);
	static void editGood(int index, int fieldIndex, Department &obj);
	static vector<ElectricalDevices*>* findGood(string findText, Department &obj);
	static ElectricalDevices* removeGood(int index, Department &obj);
};

