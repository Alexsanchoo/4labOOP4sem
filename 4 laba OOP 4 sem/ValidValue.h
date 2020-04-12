#pragma once
#include<iostream>
#include<string>
#include<regex>

using namespace std;

template<class T = int>
class ValidValue
{
public:
	static T getValue();
	static string getInitials();
	static string getString();
};

template<class T>
inline T ValidValue<T>::getValue()
{
	T value;
	while (true)
	{
		try
		{
			cin >> value;
			cin.ignore(1000, '\n');
			if (cin.gcount() > 1) throw runtime_error("extra characters");
			return value;
		}
		catch (ios_base::failure ex)
		{
			cout << "Ошибка! Введите ещё раз: ";
			cin.clear();
			while (cin.get() != '\n');
		}
		catch (runtime_error ex)
		{
			cout << "Ошибка! Введите ещё раз: ";
		}
	}
}

inline string ValidValue<string>::getInitials()
{
	string validStr;
	bool isValid = false;
	while (!isValid)
	{
		getline(cin, validStr);
		isValid = regex_match(validStr, regex("[A-ZА-ЯЁ][a-zа-яё]+"));
		if (!isValid)
		{
			cout << "Ошибка! Введите ещё раз: ";
		}
	}
	return validStr;
}

inline string ValidValue<string>::getString()
{
	string validStr;
	bool isValid = false;
	while (!isValid)
	{
		getline(cin, validStr);
		isValid = regex_match(validStr, regex("[А-Яа-яA-Za-zЁё\\-\\ \\_]+"));
		if (!isValid)
		{
			cout << "Ошибка! Введите ещё раз: ";
		}
	}
	return validStr;
}
