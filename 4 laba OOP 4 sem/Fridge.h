#pragma once
#include "ElectricalDevices.h"

class Fridge :
	public ElectricalDevices
{
public:
	Fridge(bool frost = true, double minTemp = -20.0, string nameSh = "Холодильник", string manufacturer = "Atlant",
		double costSh = 178.0, TypeDep typeSh = HOUSEHOLD) :
		ElectricalDevices(nameSh, manufacturer, costSh, typeSh), isNotFrost(frost), minTemperature(minTemp) {}
	Fridge(const Fridge &obj) : isNotFrost(obj.isNotFrost), minTemperature(obj.minTemperature), ElectricalDevices(obj) {}

	void setIsNotFrost(bool frost);
	void setMinTemp(double temp);
	bool getIsNotFrost();
	double getMinTemp();
	friend istream & operator>>(istream & in, Fridge& obj);
	friend ostream & operator<<(ostream & out, Fridge& obj);

	~Fridge() {}

private:
	bool isNotFrost;
	double minTemperature;
};

