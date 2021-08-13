#include <iostream>
#include <locale.h>
using namespace std;
#define MAX 5

struct Fila {
   int ini;
   int fim;     
   float nos[MAX];	
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int incrementa(int i) {
	int ret;
	if (i == MAX) {
		ret = 0;
	} 
	else {
		ret = i+1;
	}
	return ret;
}


int isEmpty(Fila *f) {
	return (f->ini == f->fim);
}
int count(Fila *f)
{
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim)
	{
		qtde++;
		i = incrementa(i);
	}
	return qtde;
}
int senhasGeradas(Fila *f, float v)
{
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar)
	{
		f->nos[f->fim] = v;
		f->fim = incrementa(f->fim);
	}
	return podeEnfileirar;
}

float senhasAtendidas(Fila *f)
{
	float ret;
	if (isEmpty(f))
	{
		ret = -1;
	}
	else
	{
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	int opcao = 99;
	int cont = 0;

	Fila *filaFloat = new Fila;
	filaFloat = init();


	for (int x = 0; opcao != 0 || isEmpty(filaFloat) == false; x++)
	{
		system("cls");
		cout << "0. Sair." << endl;
		cout << "1. Gerar senha." << endl;
		cout << "2. Realizar atendimento." << endl;
		cout << endl;
		cout << "Informe sua opção.: ";
		cin >> opcao;

		if (opcao == 1)
		{
			system("cls");
			cout << "Senha Registrada com sucesso!." << endl;
			cout << endl;
			cont++;
			system("pause");
			senhasGeradas(filaFloat, cont);
		}

		if (opcao == 2)
		{
			if(isEmpty(filaFloat))
			{
				system("cls");
				cout << "Fila vazia" << endl;
				system("pause");
			}

			else
			{
				system("cls");
				cout << "Senha N°" << (filaFloat->ini) + 1 << " foi atendida com sucesso!." << endl;
				cout << endl;
				cont--;
				cout << "Quantidade de senhas a serem atendidas.: " << cont << endl;
				cout << endl;
				system("pause");
				senhasAtendidas(filaFloat);
			}
		}
	}
	return 0;
}
