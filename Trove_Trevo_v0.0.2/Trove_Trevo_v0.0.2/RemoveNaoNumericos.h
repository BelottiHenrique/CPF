#pragma once
#include <string>
#include <iostream>
using namespace std;

class RemoveNaoNumericos
{
public: 

	string RetiraValoresNaoNumericos(const string& Caracteres)
	{

		string resultado;

		for (char c : Caracteres)
		{
			if (isdigit(c))
			{
				resultado += c;
			}
		}
		return resultado;
	}



};

