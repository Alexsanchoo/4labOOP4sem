#include "OrderManager.h"

void OrderManager::addGood(ElectricalDevices * good, Order & obj)
{
	obj.getGoods().push_back(good);
	obj.setTotalSum(obj.getTotalSum() + good->getCost());
}

int OrderManager::showGoods(Order & obj)
{
	if (!obj.getGoods().size())
	{
		return 0;
	}

	cout << "~~~ЗАКАЗ~~~" << endl;
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

ElectricalDevices * OrderManager::removeGood(int index, Order & obj)
{
	ElectricalDevices* good = obj.getGoods()[index];
	obj.getGoods().erase(obj.getGoods().begin() + index);
	return good;
}
