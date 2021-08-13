#include <iostream>
using namespace std;

/*Exercício 2  - Receber através de digitação uma mensagem. 

Informar se esta mensagem é ou não um dado palíndromo (no caso de haver espaços no texto, desconsiderá-los para a verificação). Exemplos:

OVO
ARARA
SOCORRAM ME SUBI NO ONIBUS EM MARROCOS*/

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	string msg = "";
	bool palindrono = true;
	int reverter = 0;

	cout << "Digite a palavra a ser analisada: " << endl;
	cin >> msg;

	for (int i = msg.length() - 1; i > 0; i--)
	{

		reverter = msg.length() - i - 1;

		if (msg.substr(i, 1) != msg.substr(reverter, 1))
		{
			palindrono = false;
			break;
		}
	}

	cout << endl << (palindrono ? "É palindromo" : "Não é palindromo");
	return 0;
}
