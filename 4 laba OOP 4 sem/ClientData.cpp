#include "ClientData.h"


ClientData::ClientData(string nameSh, string lastnameSh, string adressSh, int cardNumberSh) :
	name(nameSh), lastname(lastnameSh), adress(adressSh), cardNumber(cardNumberSh)
{
	if (name == "Василий" && lastname == "Пупкин")
	{
		throw ExpShop("error", 2);
	}
}

void ClientData::setName(string name)
{
	this->name = name;
}

void ClientData::setLastname(string lastname)
{
	this->lastname = lastname;
}

void ClientData::setAdress(string adress)
{
	this->adress = adress;
}

void ClientData::setCardNumber(int number)
{
	cardNumber = number;
}

string ClientData::getName()
{
	return name;
}

string ClientData::getLastname()
{
	return lastname;
}

string ClientData::getAdress()
{
	return adress;
}

int ClientData::getCardNumber()
{
	return cardNumber;
}