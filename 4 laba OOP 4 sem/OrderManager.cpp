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

	cout << "~~~ÇÀÊÀÇ~~~" << endl;
	for (size_t i = 0; i < obj.getGoods().size(); i++)
	{
		cout << fixed << setprecision(2) << left << 
			i + 1 << ". " << setw(15) << obj.getGoods()[i]->getName() << " | " << setw(15) << obj.getGoods()[i]->getManufacturer()
			<< " | " << obj.getGoods()[i]->getCost() << "$" << endl;
	}
	return 1;
}

ElectricalDevices * OrderManager::removeGood(int index, Order & obj)
{
	ElectricalDevices* good = obj.getGoods()[index];
	obj.getGoods().erase(obj.getGoods().begin() + index);
	return good;
}
