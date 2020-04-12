#pragma once
#include<vector>
#include "ElectricalDevices.h"
#include "ClientData.h"

using namespace std;

class Order
{
public:
	Order(ClientData *dataSh = nullptr) : data(dataSh), totalSum(0.0) {}
	Order(const Order &obj);

	void setData(ClientData *data);
	void setTotalSum(double sum);
	ClientData* getData();
	double getTotalSum();
	vector<ElectricalDevices*>& getGoods();
	~Order();

private:
	ClientData *data;
	vector<ElectricalDevices*> goods;
	double totalSum;
};

