#include "ExpShop.h"

string ExpShop::what()
{
	switch (code)
	{
	case 0:
		return exception::what();
		break;

	case 1:
		return "��� ������ �����! ������� ��� ���: ";
		break;

	case 2:
		return "� ��������� ��������� ������������ ������� \"������� ������\"!";
		break;
	}
}
