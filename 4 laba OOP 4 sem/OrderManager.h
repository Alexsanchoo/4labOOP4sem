#pragma once
#include <iostream>
#include <iomanip>
#include "ElectricalDevices.h"
#include "Order.h"
#include "Iron.h"
#include "Fridge.h"
#include "Keyboard.h"
#include "Monitor.h"

using namespace std;

class OrderManager
{
public:
	static void addGood(ElectricalDevices* good, Order &obj);
	static int showGoods(Order &obj);
	static ElectricalDevices* removeGood(int index, Order &obj);
};

