#include <iostream>
#include <locale.h>
#include <fstream>
using namespace std;

/*Exerc�cio 3 - � partir de uma lista de nomes dispon�vel em um arquivo TXT, transforma-los em nomes no formato agenda telef�nica. Exemplo:

Jos� Antonio Santos Silva
Silva, Jos� Antonio Santos*/

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	ifstream  arq("nome.txt");

	if(arq.is_open())
	{
		string linha;
		while( getline(arq, linha) )
		{
			cout << linha << endl;
			cout << endl;
			linha.erase(20, 30);
			linha.insert(0, "Silva, ");
			cout << linha << endl;
		}
		arq.close();
	}
	else
	{
		cout << "N�o foi poss�vel abrir o arquivo";
	}


	return 0;
}
