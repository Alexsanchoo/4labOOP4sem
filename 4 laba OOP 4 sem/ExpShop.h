#pragma once
#include <exception>
#include<string>

using namespace std;

class ExpShop :
	public exception
{
public:
	ExpShop(string exp, int codeExp = 0) : name(exp), code(codeExp), exception(exp.c_str()) {}
	string what();
	~ExpShop() {}

private:
	string name;
	int code;
};

