#pragma once
#include <clocale>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <locale>
#include "RemoveNaoNumericos.h"
using namespace std;


bool ValidarCPF(const string& CPF) {
	RemoveNaoNumericos SomenteNumeros;

	string CPFNumerico = SomenteNumeros.RetiraValoresNaoNumericos(CPF);


	if (CPFNumerico.empty() && CPFNumerico.length() != 11) // VERIFICA SE O CPF QUE FOI DIGITADO CONTEM 11 DIGITOS
	{
		return false;
	}

	if (all_of(CPFNumerico.begin(), CPFNumerico.end(), [=](char c) {return c == CPFNumerico[0]; }))
	{
		return false; // VERIFICA SE TODOS OS NUMEROS DIGITADOS SAO IGUAIS
	}

	// DEPOIS DE VERIFICAR, VAMOS REALIZAR UM CALCULO PARA QUE POSSAMOS IDENTIFICAR SE O CPF DIGITADO E VALIDO


	// CALCULO DO PRIMEIRO DIGITO VERIFICADOR
	int soma = 0;

	for (int i = 0; i < 9; ++i)
	{
		soma += (CPFNumerico[i] - '0') * (10 - i);
	}
	int resto = soma % 11;
	int digit1 = (resto < 2) ? 0 : 11 - resto;

	// CALCULAR O SEGUNDO DIGITO VERIFICADOR

	soma = 0;
	for (int i = 0; i < 10; ++i)
	{
		soma += (CPFNumerico[i] - '0') * (11 - i);
	}
	resto = soma % 11;
	int digito2 = (resto < 2) ? 0 : 11 - resto;


	// VERIFICAR SE OS DIGITOS CALCULADOS SQO IGUAIS AOS DIGITOS FORNECIDOS
	return CPFNumerico[9] - '0' == digit1 && CPFNumerico[10] - '0' == digito2;
}




class CPF
{
public :

	void VerificarCPFValido()
	{
	 string NovoCPF = "";
		
		while (true)
		{
			setlocale(LC_ALL, "Portuguese");

			cout << "\nPor favor informe seu CPF no formato [000.000.000-00]: ";
			cin >> NovoCPF;

			if (NovoCPF.empty())
			{
				cout << "\n\aCPF Invalido! \nO valor nao pode ser nulo! " << endl;
				cout << "\n\aPressione Enter para contnuar...";
				cin.ignore();
				cin.get();
				system("cls");
				return VerificarCPFValido();
			}
			else if (ValidarCPF(NovoCPF))
			{
				cout << "\nCPF Valido !" << endl;

				break;
			}
			else {
				cout << "\n\aCPF Invalido!" << endl;
				cout << "\n\aPressione Enter para contnuar...";
				cin.ignore();
				cin.get();
				system("cls");
				return VerificarCPFValido();
			}
			



		}
	}





};

