#include "ShopManager.h"

void ShopManager::addGood(Shop &shop)
{
	ElectricalDevices* device = nullptr;
	int ch = 0;
	while (ch != 5)
	{
		cout << "��������, ����� ����� �� ������ ��������: " << endl;
		cout << "1. �������" << endl;
		cout << "2. ����������" << endl;
		cout << "3. �����������" << endl;
		cout << "4. ����" << endl;
		cout << "5. �����" << endl;
		cout << "�������� �����: ";
		ch = ValidValue<>::getValue();

		system("cls");
		switch (ch)
		{
		case 1:
			device = new Monitor();
			cout << "������� �������� �������������: ";
			device->setManufacturer(ValidValue<string>::getString());
			cout << "������� ���� ������: ";
			device->setCost(ValidValue<double>::getValue());
			cout << "������� ������ ��������: ";
			((Monitor*)device)->setWidth(ValidValue<double>::getValue());
			cout << "������� ������ ������: ";
			((Monitor*)device)->setHeight(ValidValue<double>::getValue());
			DepartmentManager::addGood(device, shop.getComputerDep());
			cout << "������� ������� �������� � �����������!" << endl << endl;
			break;

		case 2:
			device = new Keyboard();
			cout << "������� �������� �������������: ";
			device->setManufacturer(ValidValue<string>::getString());
			cout << "������� ���� ������: ";
			device->setCost(ValidValue<double>::getValue());
			cout << "������� ���������� ������: ";
			((Keyboard*)device)->setCountKey(ValidValue<>::getValue());
			DepartmentManager::addGood(device, shop.getComputerDep());
			cout << "���������� ������� ��������� � �����������!" << endl << endl;
			break;

		case 3:
			device = new Fridge();
			cout << "������� �������� �������������: ";
			device->setManufacturer(ValidValue<string>::getString());
			cout << "������� ���� ������: ";
			device->setCost(ValidValue<double>::getValue());
			cout << "����������� ������� ����������? ( 1 - ��, 0 - ���): ";
			((Fridge*)device)->setIsNotFrost(ValidValue<bool>::getValue());
			cout << "������� ����������� ����������� ������������: ";
			((Fridge*)device)->setMinTemp(ValidValue<double>::getValue());
			DepartmentManager::addGood(device, shop.getHouseholdDep());
			cout << "����������� ������� �������� � �����������!" << endl << endl;
			break;

		case 4:
			device = new Iron();
			cout << "������� �������� �������������: ";
			device->setManufacturer(ValidValue<string>::getString());
			cout << "������� ���� ������: ";
			device->setCost(ValidValue<double>::getValue());
			cout << "������� ������������ ����������� �����: ";
			((Iron*)device)->setMaxTemp(ValidValue<double>::getValue());
			DepartmentManager::addGood(device, shop.getHouseholdDep());
			cout << "���� ������� �������� � �����������!" << endl << endl;
			break;

		case 5:
			system("cls");
			break;

		default:
			cout << "�������� �����!" << endl << endl;
			break;
		}
	}
}


void ShopManager::showGoods(Shop &shop)
{
	if (!DepartmentManager::showGoods(shop.getComputerDep()))
	{
		cout << "~~~" << shop.getComputerDep().getName() << "~~~" << endl;
		cout << "��� ������!" << endl;
	}
	cout << endl;
	if (!DepartmentManager::showGoods(shop.getHouseholdDep()))
	{
		cout << "~~~" << shop.getHouseholdDep().getName() << "~~~" << endl;
		cout << "��� ������!" << endl;
	}
}

void ShopManager::removeGood(Shop & shop)
{
	int choice = 0;
	while (choice != 3) {
		cout << "�������� �����: " << endl;
		cout << "1. ������������ �����" << endl;
		cout << "2. ������� �����" << endl;
		cout << "3. �����" << endl;
		cout << "�������� �����: ";
		choice = ValidValue<>::getValue();

		system("cls");
		switch (choice)
		{

		case 1:
		{
			int recToDel = 0;
			if (!DepartmentManager::showGoods(shop.getComputerDep())) {
				cout << "~~~" << shop.getComputerDep().getName() << "~~~" << endl;
				cout << "��� ������!" << endl;
				system("pause>>void");
				system("cls");
				break;
			}
			cout << endl << "�������� ����� ��� ��������: ";
			bool isValidInput = false;
			while (!isValidInput)
			{
				try
				{
					recToDel = ValidValue<>::getValue();
					if (recToDel < 1 || recToDel > shop.getComputerDep().getGoods().size())
					{
						throw ExpShop("error", 1);
					}
					isValidInput = true;
				}
				catch (ExpShop ex)
				{
					cout << ex.what();
				}
			}

			DepartmentManager::removeGood(recToDel - 1, shop.getComputerDep());
		}
			system("cls");
			break;

		case 2:
		{
			int recToDel = 0;
			if (!DepartmentManager::showGoods(shop.getHouseholdDep())) {
				cout << "~~~" << shop.getHouseholdDep().getName() << "~~~" << endl;
				cout << "��� ������!" << endl;
				system("pause>>void");
				system("cls");
				break;
			}
			cout << endl << "�������� ����� ��� ��������: ";
			bool isValidInput = false;
			while (!isValidInput)
			{
				try
				{
					recToDel = ValidValue<>::getValue();
					if (recToDel < 1 || recToDel > shop.getHouseholdDep().getGoods().size())
					{
						throw ExpShop("error", 1);
					}
					isValidInput = true;
				}
				catch (ExpShop ex)
				{
					cout << ex.what();
				}
			}

			DepartmentManager::removeGood(recToDel - 1, shop.getHouseholdDep());
		}
		system("cls");
		break;

		case 3:
			break;

		default:
			break;
		}
	}
}

void ShopManager::editGood(Shop & shop)
{
	int choice = 0;
	while (choice != 3) {
		cout << "�������� �����: " << endl;
		cout << "1. ������������ �����" << endl;
		cout << "2. ������� �����" << endl;
		cout << "3. �����" << endl;
		cout << "�������� �����: ";
		choice = ValidValue<>::getValue();

		system("cls");
		switch (choice)
		{

		case 1:
		{
			int recToEdit = 0;
			if (!DepartmentManager::showGoods(shop.getComputerDep())) {
				cout << "~~~" << shop.getComputerDep().getName() << "~~~" << endl;
				cout << "��� ������!" << endl;
				system("pause>>void");
				system("cls");
				break;
			}
			cout << endl << "�������� ����� ��� ��������������: ";
			bool isValidInput = false;
			while (!isValidInput)
			{
				try
				{
					recToEdit = ValidValue<>::getValue();
					if (recToEdit < 1 || recToEdit > shop.getComputerDep().getGoods().size())
					{
						throw ExpShop("error", 1);
					}
					isValidInput = true;
				}
				catch (ExpShop ex)
				{
					cout << ex.what();
				}
			}

			system("cls");
			int ch = 0;
			while (ch != 3) {
				cout << "�������� ���� ��� ��������������:" << endl;
				cout << "1. �������� �������������" << endl;
				cout << "2. ����" << endl;
				cout << "3. �����" << endl;
				cout << "�������� �����: ";
				ch = ValidValue<>::getValue();

				system("cls");
				switch (ch) {
				case 1:
					DepartmentManager::editGood(recToEdit - 1, 1, shop.getComputerDep());
					system("cls");
					break;

				case 2:
					DepartmentManager::editGood(recToEdit - 1, 2, shop.getComputerDep());
					system("cls");
					break;

				case 3:system("cls");
					break;

				default:
					cout << "�������� �����!" << endl << endl;
				}
			}
		}
		system("cls");
		break;

		case 2:
		{
			int recToEdit = 0;
			if (!DepartmentManager::showGoods(shop.getHouseholdDep())) {
				cout << "~~~" << shop.getHouseholdDep().getName() << "~~~" << endl;
				cout << "��� ������!" << endl;
				system("pause>>void");
				system("cls");
				break;
			}
			cout << endl << "�������� ����� ��� ��������������: ";
			bool isValidInput = false;
			while (!isValidInput)
			{
				try
				{
					recToEdit = ValidValue<>::getValue();
					if (recToEdit < 1 || recToEdit > shop.getHouseholdDep().getGoods().size())
					{
						throw ExpShop("error", 1);
					}
					isValidInput = true;
				}
				catch (ExpShop ex)
				{
					cout << ex.what();
				}
			}

			system("cls");
			int ch = 0;
			while (ch != 3) {
				cout << "�������� ���� ��� ��������������:" << endl;
				cout << "1. �������� �������������" << endl;
				cout << "2. ����" << endl;
				cout << "3. �����" << endl;
				cout << "�������� �����: ";
				ch = ValidValue<>::getValue();

				system("cls");
				switch (ch) {
				case 1:
					DepartmentManager::editGood(recToEdit - 1, 1, shop.getHouseholdDep());
					system("cls");
					break;

				case 2:
					DepartmentManager::editGood(recToEdit - 1, 2, shop.getHouseholdDep());
					system("cls");
					break;

				case 3:system("cls");
					break;

				default:
					cout << "�������� �����!" << endl << endl;
				}
			}
		}
		system("cls");
		break;

		case 3:
			break;

		default:
			break;
		}
	}
}

void ShopManager::findGood(Shop & shop)
{
	string findStr;
	cout << "����� (��������� ������: �����, �������������, ����): "; getline(cin, findStr);
	cout << endl;
	
	vector<ElectricalDevices*>* vecComp = DepartmentManager::findGood(findStr, shop.getComputerDep());
	vector<ElectricalDevices*>* vecHouse = DepartmentManager::findGood(findStr, shop.getHouseholdDep());

	cout << "~~~" << shop.getComputerDep().getName() << "~~~" << endl;
	if (vecComp->size())
	{
		for (size_t i = 0; i < vecComp->size(); i++)
		{
			cout << "#" << i + 1 << endl;
			cout << "�����: " << vecComp->at(i)->getName() << endl;
			cout << "�������������: " << vecComp->at(i)->getManufacturer() << endl;
			cout << fixed << setprecision(2) << "����: " << vecComp->at(i)->getCost() << "$" << endl;

			switch (vecComp->at(i)->getTypeGood())
			{
			case MONITOR:
			{
				cout << fixed << setprecision(2) << "������ ��������: " << ((Monitor*)vecComp->at(i))->getWidth() << endl;
				cout << fixed << setprecision(2) << "������ ��������: " << ((Monitor*)vecComp->at(i))->getHeight() << endl;
			}
			break;

			case KEYBOARD:
			{
				cout << "���������� ������ �� ����������: " << ((Keyboard*)vecComp->at(i))->getCountKey() << endl;
			}
			break;

			default:
				break;
			}
			cout << endl;
		}
	}
	else
	{
		cout << "��� ����������!" << endl;
	}
	cout << endl;
	
	cout << "~~~" << shop.getHouseholdDep().getName() << "~~~" << endl;
	if (vecHouse->size())
	{
		for (size_t i = 0; i < vecHouse->size(); i++)
		{
			cout << "#" << i + 1 << endl;
			cout << "�����: " << vecHouse->at(i)->getName() << endl;
			cout << "�������������: " << vecHouse->at(i)->getManufacturer() << endl;
			cout << fixed << setprecision(2) << "����: " << vecHouse->at(i)->getCost() << "$" << endl;

			switch (vecHouse->at(i)->getTypeGood())
			{
			case FRIDGE:
			{
				cout << "������� \"not frost\": " << (((Fridge*)vecHouse->at(i))->getIsNotFrost() ? "����" : "���") << endl;
				cout << fixed << setprecision(2) << "����������� �����������: " << ((Fridge*)vecHouse->at(i))->getMinTemp() << "�C" << endl;
			}
			break;

			case IRON:
			{
				cout << fixed << setprecision(2) << "������������ �����������: " << ((Iron*)vecHouse->at(i))->getMaxTemp() << "�C" << endl;
			}
			break;

			default:
				break;
			}
			cout << endl;
		}
	}
	else
	{
		cout << "��� ����������!" << endl;
	}

	delete vecComp;
	vecComp = nullptr;
	delete vecHouse;
	vecHouse = nullptr;
}


void ShopManager::placeOrder(ClientData *&clientData, Order &order, Shop & shop)
{
	{
		int ch = 0;
		while (ch != 7)
		{
			cout << "���������� ������: " << endl;
			cout << "1. ���������� ������ ������ �������" << endl;
			cout << "2. ������� ����� �� ������������� ������" << endl;
			cout << "3. ������� ����� �� �������� ������" << endl;
			cout << "4. ����������� ��������� ������" << endl;
			cout << "5. ������ ����� �� ������" << endl;
			cout << "6. ��������� �����" << endl;
			cout << "7. �����" << endl;
			cout << "�������� �����: ";
			ch = ValidValue<>::getValue();

			system("cls");
			switch (ch)
			{
			case 1:
				if (clientData == nullptr)
				{
					try
					{
						cout << "������� ���: ";  string name = ValidValue<string>::getInitials();
						cout << "������� �������: "; string lastname = ValidValue<string>::getInitials();
						string adress;
						cout << "������� �����: "; getline(cin, adress);
						cout << "������� ����� �����: "; int cardNumber = ValidValue<>::getValue();
						system("cls");
						clientData = new ClientData(name, lastname, adress, cardNumber);
						order.setData(clientData);
					}
					catch (bad_alloc ex)
					{
						cout << "ERROR: " << ex.what() << "!" << endl << endl;
					}
					catch (ExpShop ex)
					{
						cout << ex.what() << endl << endl;
					}
				}
				else
				{
					cout << "������ � ������� ��� ���������!" << endl << endl;
				}
				break;

			case 2:
			{
				int ch = 0;
				ElectricalDevices *device = nullptr;
				if (DepartmentManager::showGoods(shop.getComputerDep()))
				{
					cout << endl << "�������� ����� ������: ";
					bool isValidInput = false;
					while (!isValidInput)
					{
						try
						{
							ch = ValidValue<>::getValue();
							if (ch <  1 || ch > shop.getComputerDep().getGoods().size())
							{
								throw ExpShop("error", 1);
							}
							isValidInput = true;
						}
						catch (ExpShop ex)
						{
							cout << ex.what();
						}
					}


					device = DepartmentManager::removeGood(ch - 1, shop.getComputerDep());
					OrderManager::addGood(device, order);
					system("cls");
				}
				else
				{
					cout << "� ������������ ������ ���������� �����!" << endl << endl;
				}
			}
			break;

			case 3:
			{
				int ch = 0;
				ElectricalDevices* device = nullptr;
				if (DepartmentManager::showGoods(shop.getHouseholdDep()))
				{
					bool isValidInput = false;
					while (!isValidInput)
					{
						try
						{
							ch = ValidValue<>::getValue();
							if (ch < 1 || ch > shop.getHouseholdDep().getGoods().size())
							{
								throw ExpShop("error", 1);
							}
							isValidInput = true;
						}
						catch (ExpShop ex)
						{
							cout << ex.what();
						}
					}
					device = DepartmentManager::removeGood(ch - 1, shop.getHouseholdDep());
					OrderManager::addGood(device, order);
					system("cls");
				}
				else
				{
					cout << "� ������� ������ ���������� �����!" << endl << endl;
				}
			}
			break;

			case 4:
				if (!OrderManager::showGoods(order))
				{
					cout << "~~~�����~~~" << endl;
					cout << "��� �������!" << endl;
				}
				system("pause>>void");
				system("cls");
				break;

			case 5:
			{
				int ch = 0;
				if (OrderManager::showGoods(order))
				{
					cout << "�������� �����, ������� ������ ������: ";
					bool isValidInput = false;
					while (!isValidInput)
					{
						try
						{
							ch = ValidValue<>::getValue();
							if (ch < 1 || ch > order.getGoods().size())
							{
								throw ExpShop("error", 1);
							}
							isValidInput = true;
						}
						catch (ExpShop ex)
						{
							cout << ex.what();
						}
					}

					ElectricalDevices* good = OrderManager::removeGood(ch - 1, order);
					switch (good->getType())
					{
					case HOUSEHOLD:
						DepartmentManager::addGood(good, shop.getHouseholdDep());
						break;

					case COMPUTER:
						DepartmentManager::addGood(good, shop.getComputerDep());
						break;

					default:
						break;
					}
					system("cls");
				}
				else
				{
					cout << "� ������ ��� ��� �������!" << endl << endl;
				}
			}
			break;

			case 6:
			{
				if (clientData != nullptr && OrderManager::showGoods(order))
				{
					cout << endl;
					cout << "����� �����: " << order.getTotalSum() << "$" << endl;
					system("pause>>void");
					system("cls");
					order.~Order();
					shop.~Shop();
					delete clientData;
					exit(0);
				}
				else
				{
					cout << "������ ����� ���� ��� ������ � ������� ��� �� ���������!" << endl << endl;
				}
			}
			break;

			case 7:
				break;

			default:
				cout << "�������� �����!" << endl << endl;
				break;
			}
		}
	}
}