#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct Funcionario
{
	int prontuario;
	double salario;
	string  nome;
	struct Funcionario *prox; 
};

Funcionario* init()
{
	return NULL;	
}

void lista(Funcionario* lista)
{
	Funcionario* aux;
	aux= lista;
	int totalFunc = 0;
	
	while(aux!=NULL)
	{
		totalFunc++;
		cout << "Prontuario: " << aux->prontuario << " - Nome: " << aux->nome << " - Salario: " << aux->salario << endl;
		cout << endl;
		aux=aux->prox;
	}
	
	cout << "Total de funcionarios: " << totalFunc << endl;
}

Funcionario* excluir(Funcionario* lista, int i)
{
	Funcionario *aux;
	Funcionario *ant = NULL;
	aux=lista;
	
	
	while(aux != NULL && aux->prontuario != i)
	{
		ant = aux;
		aux = aux->prox;
	}
	
	if(aux == NULL)
	{
		return lista;	
	}
	if(ant == NULL)
	{
		lista = lista->prox;
	}
	else
	{
		ant->prox = aux->prox;
	}
	return lista;
}

Funcionario* pesquisar(Funcionario* lista, int prontuario) {
	Funcionario* aux;
	aux = lista;
	
	while (aux != NULL && aux->prontuario != prontuario) {
		aux = aux->prox;
	}
	return aux;
}

Funcionario* incluir(Funcionario* lista, int prontuario,double salario,string nome){
	
	Funcionario *procurado = pesquisar(lista, prontuario);
	
	if(procurado != NULL) {
		cout << "Funcionario com esse prontuario ja cadastrado." << endl;
		return lista;
	}
	
	Funcionario* novo = new Funcionario();
	novo->prontuario = prontuario;
  novo->salario = salario;
  novo->nome = nome;
	novo->prox = lista;
	
	return novo;
}

void menu()
{
	bool menu = true;
	int op = 0;
	Funcionario *listaFunc;
	listaFunc = init();
    
  while (menu)
	{
		string nome = "";
		double salario = 0;
		double total;	
		int prontuario = 0;
        	
		cout << "\nSelecione uma opcao:"<<endl;
		cout << "\n1.Cadastrar funcionario"<<endl;
		cout << "2.Excluir funcionario"<<endl;
		cout << "3.Pesquisar funcionario"<<endl;
		cout << "4.Listar funcionarios"<<endl;
		cout << "0.SAIR"<<endl;
		cin >> op;
		cout << endl;
        
		switch(op)
		{
			case 0: 
				cout<<"Obrigado\n\n"<<endl;
				menu = false;
				break;
			case 1: 
				for(int i=0;i<1;i++)
				{
				cout << "Digite o nome do Funcionario:" << endl;
				cin >> nome;
				cout << "Digite o salario do Funcionario:" << endl;
				cin >> salario;
				cout << "Digite o prontuario do Funcionario" << endl;
				cin >> prontuario;
               
		        total=total+salario;
				listaFunc = incluir(listaFunc, prontuario, salario, nome);
				}
				
			
				break;
			case 2: 
				cout << "Digite o prontuario do Funcionario" << endl;
				cin >> prontuario;
				
				listaFunc = excluir(listaFunc, prontuario);
				break;
			case 3: {
				cout << "Digite o prontuario do Funcionario" << endl;
				cin >> prontuario;
				
				Funcionario *procurado = pesquisar(listaFunc, prontuario);
				if(procurado != NULL) {
					cout << "Prontuario: " << procurado->prontuario << " - Nome: " << procurado->nome << " - Salario: " << procurado->salario << endl;
				
				} else {
					cout << "Funcionario nao encontrado." << endl;
				}
				break;
			}
			case 4: 
				lista(listaFunc);
					cout<<"Salario total dos funcionarios eh: "<<total<<endl;
				break;  
		}
  }
}

int main(int argc, char** argv) {

    menu();
    return 0;
}
/*
� partir da estrutura "Funcionario" descrita abaixo:

Funcionario
  - prontuario: int
  - nome: string
  - salario: double
Elabore um programa que permita administrar uma lista de funcion�rios e, atrav�s de um menu, ofere�a as seguintes op��es:

   0. Sair
   1. Incluir
   2. Excluir
   3. Pesquisar
   4. Listar
OBSERVA��ES:

a) N�o poder�o ser cadastrados funcion�rios com mesmo prontu�rio;

b) A pesquisa de funcion�rio dever� utilizar o atributo "Prontu�rio" como crit�rio e, quando encontrado, dever�o ser exibidos os demais atributos;

c) A listagem dos funcion�rios dever� apresentar todos os seus atributos e, ao final, informar o total dos sal�rios.
*/