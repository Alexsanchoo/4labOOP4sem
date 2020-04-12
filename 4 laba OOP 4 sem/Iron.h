#pragma once
#include "ElectricalDevices.h"
class Iron :
	public ElectricalDevices
{
public:
	Iron(double maxTemp = 200.0, string nameSh = "Óòþã", string manufacturer = "Philips",
		double costSh = 120.0, TypeDep typeSh = HOUSEHOLD) :
	ElectricalDevices(nameSh, manufacturer, costSh, typeSh), maxTemperature(maxTemp) {}
	Iron(const Iron &obj) : ElectricalDevices(obj), maxTemperature(obj.maxTemperature) {}
	
	void setMaxTemp(double temp);
	double getMaxTemp();
	friend istream & operator>>(istream & in, Iron& obj);
	friend ostream & operator<<(ostream & out, Iron& obj);

	~Iron() {}

private:
	double maxTemperature;
};

