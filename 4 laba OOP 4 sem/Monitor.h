#pragma once
#include "ElectricalDevices.h"
class Monitor :
	public ElectricalDevices
{
public:
	Monitor(double widthSh = 1920.0, double heightSh = 1080.0, string nameSh = "Монитор",
		string manufacturer = "Panasonic", double costSh = 350.43, TypeDep typeSh = COMPUTER) :
		ElectricalDevices(nameSh, manufacturer, costSh, typeSh), width(widthSh), height(heightSh) {}
	Monitor(const Monitor &obj) : ElectricalDevices(obj), width(obj.width), height(obj.height) {}

	void setWidth(double width);
	void setHeight(double height);
	double getWidth();
	double getHeight();
	friend istream & operator>>(istream & in, Monitor& obj);
	friend ostream & operator<<(ostream & out, Monitor& obj);

	~Monitor() {}

private:
	double width;
	double height;
};

