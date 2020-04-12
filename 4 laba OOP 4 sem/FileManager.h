#pragma once
#include<fstream>
#include<string>
#include<vector>
#include "ElectricalDevices.h"
#include "Fridge.h"
#include "Iron.h"
#include "Monitor.h"
#include "Keyboard.h"

using namespace std;

class FileManager
{
public:
	static int readFile(string fileName, vector<ElectricalDevices*>& vec);
	static int writeFile(string fileName, vector<ElectricalDevices*>& vec);
};