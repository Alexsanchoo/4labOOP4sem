#pragma once
#include "Shop.h"
#include "ValidValue.h"
#include "ElectricalDevices.h"
#include "Fridge.h"
#include "Iron.h"
#include "Monitor.h"
#include "Keyboard.h"
#include "DepartmentManager.h"
#include "ClientData.h"
#include "Order.h"
#include "OrderManager.h"
#include "ExpShop.h"

class ShopManager
{
public:
	static void addGood(Shop &shop);
	static void showGoods(Shop &shop);
	static void removeGood(Shop &shop);
	static void editGood(Shop &shop);
	static void findGood(Shop &shop);
	static void placeOrder(ClientData *&clientData, Order &order, Shop &shop);
};

