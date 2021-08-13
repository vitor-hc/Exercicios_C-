#include <iostream>

using namespace std;

void zerarLugares(bool lugar[15][40]) {
	for(int i = 0; i < 15; i++){
		for(int x = 0; x < 40; x++){
			lugar[i][x] = 0;
		}
	}
}

void opcaoUm(bool lugar[15][40]) {
	int fileira = 0, poltrona = 0;
	
	do {
		
		do {
			
			cout << endl;
			cout << "Digite a fileira (1 a 15):" << endl;
			cin >> fileira;
			cout << "Digite a poltrona (1 a 40):" << endl;
			cin >> poltrona;
			
		} while(fileira > 15 || fileira < 1 || poltrona > 40 || poltrona < 1);
	
	if(lugar[fileira-1][poltrona-1] == 1) {
		cout << "O lugar ja esta reservado, selecione outro assento. \n" << endl;
	}
	
	}while(lugar[fileira-1][poltrona-1] == 1);
	
	lugar[fileira-1][poltrona-1] = 1;
	cout << "Poltrona reservada com sucesso!" << endl;
	cout << endl;
}

void opcaoDois(bool lugar[15][40]) {
	cout << endl;
	for(int i = 0; i < 15; i++){
		
		if(i == 0) {
			for(int x = 0; x < 40; x++){
				if(x < 9) {
					if(x == 0){
						cout << "00 -";
					}
					cout << " 00" << x+1;	
				}else {
					cout << " 0" << x+1;
				}
			}
			cout << endl;
		}
		
		if(i < 9) {
			cout << "0" << i+1 << " -";	
		}else {
			cout << i+1 << " -";
		}
		
		for(int x = 0; x < 40; x++){
			
			if(lugar[i][x] == 0){
				cout << " |.|";
			} else {
				cout << " |#|";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void opcaoTres(bool lugar[15][40]) {
	float valorTotal = 0;
	int qtdLugares = 0;
	
	for(int i = 0; i < 15; i++){
		for(int x = 0; x < 40; x++){
			
			if(lugar[i][x] == 1){
				qtdLugares++;
				
				if(i < 5) {
					valorTotal += 50;
				}else if(i < 10) {
					valorTotal += 30;
				}else {
					valorTotal += 15;
				}
			}
		
		}
	}
	
	cout << endl;
	cout << "Quantidade de assentos reservados : " << qtdLugares << endl;
	cout.precision(2);
	cout << "Valor da bilheteria: R$ " << fixed << valorTotal << endl;
	cout << endl;
}

int main(int argc, char** argv)
{
	bool lugar[15][40];
	int escolha = 0;
	
	zerarLugares(lugar);
	
	do {
		
		cout << endl;
		cout << "0. Finalizar" << endl;
		cout << "1. Reservar poltrona" << endl;
		cout << "2. Mapa de ocupac�o" << endl;
		cout << "3. Faturamento" << endl;
		cin >> escolha;
		
		switch(escolha)
		{
		case 1:
			opcaoUm(lugar);
			break;
		case 2:
			opcaoDois(lugar);
			break;
		case 3:
			opcaoTres(lugar);
			break;
		}
		
	}while(escolha != 0);
	
    return 0;       
}

/*
1. Projeto Bilheteria:

Um teatro possui 600 lugares dispostos em 15 fileiras com 40 poltronas cada.

Deseja-se um sistema de controle de ocupa��o que ofere�a as seguintes op��es, atrav�s de um seletor:

0.	Finalizar
1.	Reservar poltrona
2.	Mapa de ocupa��o
3.	Faturamento
A op��o 1 dever� solicitar a informa��o da fileira e da poltrona. Os dados devem ser consistidos no sentido
da garantia de serem v�lidos. Caso o lugar esteja vago, efetuar a reserva e informar o usu�rio do sucesso da
opera��o. Caso o lugar j� se encontre ocupado, alertar o usu�rio com uma mensagem.

A op��o 2 dever� gerar na tela um �mapa� de ocupa��o do teatro com uma legenda onde:

�.� representa lugar vago
�#� representa lugar ocupado
A op��o 3 dever� apresentar na tela as seguintes informa��es:

Qtde de lugares ocupados: 	999
Valor da bilheteria: 		R$ 9999,99
Sabendo-se que:

Fileiras 1 a 5:       R$ 50,00
Fileiras 6 a 10:     R$ 30,00
Fileiras 11 a 15:   R$ 15,00
*/