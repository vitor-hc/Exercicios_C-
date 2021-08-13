#include <iostream>
using namespace std;

/*Exerc�cio 2  - Receber atrav�s de digita��o uma mensagem. 

Informar se esta mensagem � ou n�o um dado pal�ndromo (no caso de haver espa�os no texto, desconsider�-los para a verifica��o). Exemplos:

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

	cout << endl << (palindrono ? "� palindromo" : "N�o � palindromo");
	return 0;
}
