#include "DepartmentManager.h"

void DepartmentManager::addGood(ElectricalDevices * good, Department & obj)
{
	obj.getGoods().push_back(good);
}

int DepartmentManager::showGoods(Department & obj)
{
	if (!obj.getGoods().size())
	{
		return 0;
	}

	cout << "~~~" << obj.getName() << "~~~" << endl;
	for (size_t i = 0; i < obj.getGoods().size(); i++)
	{
		cout << "#" << i + 1 << endl;
		cout << "Товар: " << obj.getGoods()[i]->getName() << endl;
		cout << "Производитель: " << obj.getGoods()[i]->getManufacturer() << endl;
		cout << fixed << setprecision(2) << "Цена: " << obj.getGoods()[i]->getCost() << "$" << endl;

		switch (obj.getGoods()[i]->getTypeGood())
		{
		case FRIDGE:
		{
			cout << "Функция \"not frost\": " << (((Fridge*)obj.getGoods()[i])->getIsNotFrost() ? "есть" : "нет") << endl;
			cout << fixed << setprecision(2) << "Минимальная температура: " << ((Fridge*)obj.getGoods()[i])->getMinTemp() << "°C" << endl;
		}
			break;

		case IRON:
		{
			cout << fixed << setprecision(2) << "Максимальная температура: " << ((Iron*)obj.getGoods()[i])->getMaxTemp() << "°C" << endl;
		}
			break;

		case MONITOR:
		{
			cout << fixed << setprecision(2) << "Ширина монитора: " << ((Monitor*)obj.getGoods()[i])->getWidth() << endl;
			cout << fixed << setprecision(2) << "Высота монитора: " << ((Monitor*)obj.getGoods()[i])->getHeight() << endl;
		}
			break;

		case KEYBOARD:
		{
			cout << "Количество клавиш на клавиатуре: " << ((Keyboard*)obj.getGoods()[i])->getCountKey() << endl;
		}
			break;

		default:
			break;
		}
		cout << endl;
	}
	return 1;
}

void DepartmentManager::editGood(int index, int fieldIndex, Department & obj)
{
	cout << "Название товара: " << obj.getGoods()[index]->getName() << endl;
	switch (fieldIndex) {
	case 1:
	{
		cout << "Производитель: " << obj.getGoods()[index]->getManufacturer() << endl << endl;
		cout << "Введите нового производителя: ";
		obj.getGoods()[index]->setManufacturer(ValidValue<string>::getString());
	}
		break;

	case 2:
	{
		cout << "Цена: " << obj.getGoods()[index]->getCost() << "$" << endl << endl;
		cout << "Введите новую цену: ";
		obj.getGoods()[index]->setCost(ValidValue<double>::getValue());
	}
		break;

	default:
		return;
	}
}

vector<ElectricalDevices*>* DepartmentManager::findGood(string findText, Department & obj)
{
	vector<ElectricalDevices*>* vec = new vector<ElectricalDevices*>;
	regex find(UpperCase(findText));

	for (size_t i = 0; i < obj.getGoods().size(); i++)
	{
		if (regex_search(UpperCase(obj.getGoods()[i]->getName()), find) ||
			regex_search(UpperCase(obj.getGoods()[i]->getManufacturer()), find) ||
			regex_search(to_string(obj.getGoods()[i]->getCost()), find))
		{
			vec->push_back(obj.getGoods()[i]);
		}
	}
	return vec;
}

ElectricalDevices * DepartmentManager::removeGood(int index, Department & obj)
{
	ElectricalDevices* temp = obj.getGoods()[index];
	obj.getGoods().erase(obj.getGoods().begin() + index);
	return temp;
}
