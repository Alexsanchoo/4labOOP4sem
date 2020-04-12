#pragma once
#include<iostream>
#include<string>
#include "ValidValue.h"
#include "ExpShop.h"

using namespace std;

class ClientData
{
public:
	ClientData(string nameSh = "", string lastnameSh = "", string adressSh = "", int cardNumberSh = 0);
	ClientData(const ClientData &obj) : name(obj.name), lastname(obj.lastname), adress(obj.adress), cardNumber(obj.cardNumber) {}

	void setName(string name);
	void setLastname(string lastname);
	void setAdress(string adress);
	void setCardNumber(int number);
	string getName();
	string getLastname();
	string getAdress();
	int getCardNumber();
	~ClientData() {}

private:
	string name;
	string lastname;
	string adress;
	int cardNumber;
};

