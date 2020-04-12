#include "Functions.h"



char ToUpCase(char symbol)
{
	if ((symbol >= 'à' && symbol <= 'ÿ') || (symbol >= 'a' && symbol <= 'z'))
	{
		symbol -= 32;
	}
	else if (symbol == '¸')
	{
		symbol -= 16;
	}
	return symbol;
}

string UpperCase(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		word.at(i) = ToUpCase(word.at(i));
	}
	return word;
}