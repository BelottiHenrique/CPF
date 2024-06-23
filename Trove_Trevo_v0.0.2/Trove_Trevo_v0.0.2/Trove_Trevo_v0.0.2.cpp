// Trove_Trevo_v0.0.2.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include "CPF.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <locale>










int main()
{
	
	CPF PedeNovoCPF;

	PedeNovoCPF.VerificarCPFValido();

	


	cout << "\n\aPressione Enter para continuar...";
	cin.ignore();
	cin.get();
	system("cls");


	return 0;
}
