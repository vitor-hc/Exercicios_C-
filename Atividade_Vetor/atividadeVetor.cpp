#include <iostream>
#include <locale.h>
using namespace std;


struct No
{
	int dado;
	int dadoPar;
	int dadoImpar;
	struct No *prox;
	struct No *proxPar;
	struct No *proxImpar;
};

struct Pilha
{
	No *topo;
	No *topoPar;
	No *topoImpar;
};

Pilha* init()
{
	Pilha *p = new Pilha;
	p->topo = NULL;
	p->topoPar = NULL;
	p->topoImpar = NULL;
	return p;
}

void push(Pilha *p, int v)
{
	No *no = new No;
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

void pushPar(Pilha *par, int v)
{
	No *no = new No;
	no->dadoPar = v;
	no->proxPar = par->topoPar;
	par->topoPar = no;
}

void pushImpar(Pilha *impar, int v)
{
	No *no = new No;
	no->dadoImpar = v;
	no->proxImpar = impar->topoImpar;
	impar->topoImpar = no;
}

int pop(Pilha *p)
{
	int ret;
	int podeDesempilhar = (p->topo != NULL);
	if (podeDesempilhar)
	{
		No *no = p->topo;
		ret = no->dado;
		p->topo = p->topo->prox;
		free(no);
	}
	else
	{
		ret = -1;
	}
	return ret;
}

void print(Pilha* p)
{
	No* n;
	n = p->topo;
	while (n != NULL)
	{
		cout << n->dado << endl;
		n = n->prox;
	}
	cout << "--------------------" << endl;
}

void printPar (Pilha* par)
{
	No* n;
	n = par->topoPar;
	while (n != NULL)
	{
		cout << n->dadoPar << endl;
		n = n->proxPar;
	}
	cout << "--------------------" << endl;
}

void printImpar (Pilha* impar)
{
	No* n;
	n = impar->topoImpar;
	while (n != NULL)
	{
		cout << n->dadoImpar << endl;
		n = n->proxImpar;
	}
	cout << "--------------------" << endl;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	Pilha *pilhaInt;
	pilhaInt = init();
	int num;
	int teste = -999999999;
	int resto;
	int impar;
	int par;

	for(int i = 0; i < 30; i++)
	{
		cout << "Digite o " << i + 1 << "� n�mero de 30 n�meros de forma crescente: " << endl;
		cin >> num;

		if(teste > num)
		{
			do
			{
				cout << "Digite o " << i + 1 << "� novamente, lembrando que precisa ser maior que o anterior digitado" << endl;
				cin >> num;
			}
			while(teste > num);
			teste = num;
			push(pilhaInt, num);
		}

		else
		{
			teste = num;
			push(pilhaInt, num);
		}

		resto = num % 2;

		if(resto == 0)
		{
			par = num;
			pushPar(pilhaInt, par);
		}

		else
		{
			impar = num;
			pushImpar(pilhaInt, impar);
		}

		system("cls");
	}
	
	cout << "Valores pares." << endl;
	printPar(pilhaInt);
	cout << "Valores impares." << endl;
	printImpar(pilhaInt);

	for(int i = 0; i < 30; i++)
	{
		cout << "Valores desempilhados: " << pop(pilhaInt) << endl;
	}
	return 0;
}
