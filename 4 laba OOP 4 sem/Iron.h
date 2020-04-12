#pragma once
#include "ElectricalDevices.h"
class Iron :
	public ElectricalDevices
{
public:
	Iron(double maxTemp = 200.0, string nameSh = "Óòþã", string manufacturer = "Philips",
		double costSh = 120.0, TypeGood typeSh = HOUSEHOLD) :
	ElectricalDevices(nameSh, manufacturer, costSh, typeSh), maxTemperature(maxTemp) {}
	Iron(const Iron &obj) : ElectricalDevices(obj), maxTemperature(obj.maxTemperature) {}
	
	void setMaxTemp(double temp);
	double getMaxTemp();

	~Iron() {}

private:
	double maxTemperature;
};

