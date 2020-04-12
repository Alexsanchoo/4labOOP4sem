#include "Order.h"

Order::Order(const Order & obj) : data(obj.data), totalSum(obj.totalSum)
{
	for (size_t i = 0; i < obj.goods.size(); i++)
	{
		goods.push_back(obj.goods[i]);
	}
}

void Order::setData(ClientData * data)
{
	this->data = data;
}

void Order::setTotalSum(double sum)
{
	totalSum = sum;
}

ClientData * Order::getData()
{
	return data;
}

double Order::getTotalSum()
{
	return totalSum;
}

vector<ElectricalDevices*>& Order::getGoods()
{
	return goods;
}

Order::~Order()
{
	for (size_t i = 0; i < goods.size(); i++)
	{
		delete goods[i];
		goods[i] = nullptr;
	}
}
