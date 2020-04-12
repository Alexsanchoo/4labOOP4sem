#include "FileManager.h"

int FileManager::readFile(string fileName, vector<ElectricalDevices*>& vec)
{
	ifstream fin(fileName);
	if (!fin.is_open())
	{
		ofstream fout(fileName);
		if (!fout) { return 0; }
		fout.close();
		return 1;
	}
	if (!fin) { return 0; }
	
	while (true)
	{
		int typeGood;
		ElectricalDevices* device = nullptr;
		fin >> typeGood;
		switch ((TypeGood)typeGood)
		{
		case FRIDGE:
		{
			Fridge fridge; fin >> fridge;
			device = new Fridge(fridge);
		}
			break;

		case IRON:
		{
			Iron iron; fin >> iron;
			device = new Iron(iron);
		}
			break;

		case MONITOR:
		{
			Monitor monitor; fin >> monitor;
			device = new Monitor(monitor);
		}
			break;

		case KEYBOARD:
		{
			Keyboard keyboard; fin >> keyboard;
			device = new Keyboard(keyboard);
		}
			break;

		default:
			break;
		}

		if (fin.eof()) { break; }
		if (!fin) { return 0; }
		vec.push_back(device);
	}
	fin.close();
	return 1;
}

int FileManager::writeFile(string fileName, vector<ElectricalDevices*>& vec)
{
	ofstream fout(fileName, ios_base::trunc);
	if (!fout) { return 0; }

	for (size_t i = 0; i < vec.size(); i++)
	{
		switch (vec[i]->getTypeGood())
		{
		case FRIDGE:
		{
			fout << FRIDGE << " ";
			Fridge* fridge = dynamic_cast<Fridge*>(vec[i]);
			fout << *fridge;
		}
			break;

		case IRON:
		{
			fout << IRON << " ";
			Iron* iron = dynamic_cast<Iron*>(vec[i]);
			fout << *iron;
		}
			break;

		case MONITOR:
		{
			fout << MONITOR << " ";
			Monitor* monitor = dynamic_cast<Monitor*>(vec[i]);
		}
			break;

		case KEYBOARD:
		{
			fout << KEYBOARD << " ";
			Keyboard* keyboard = dynamic_cast<Keyboard*>(vec[i]);
		}
			break;

		default:
			break;
		}
		if (!fout) { return 0; }
	}
	fout.close();
	return 1;
}