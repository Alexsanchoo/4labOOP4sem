#include "ExpShop.h"

string ExpShop::what()
{
	switch (code)
	{
	case 0:
		return exception::what();
		break;

	case 1:
		return "Нет такого номер! Введите ещё раз: ";
		break;

	case 2:
		return "В программе запрещено использовать клиента \"Василий Пупкин\"!";
		break;
	}
}
