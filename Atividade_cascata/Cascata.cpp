#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <windows.h>
#define tam 100
using namespace std;

/*Exerc�cio 1  - Receber atrav�s de digita��o uma mensagem. 

Apresentar esta mensagem, centralizada, na linha 5 da tela.

� partir da�, cada letra desta mensagem dever� "cair", da linha 5 at� a linha 20, simulando uma "cascata". Ao final, a mensagem dever� estar toda apresentada na linha 20.*/

void gotoxy(short x, short y)
{
	COORD coord = {x, y};
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	char msg[tam];
	string msgU = "";
	int col = 50;
	int y = 1;

	cout << "Digite uma mensagem." << endl;
	fgets(msg, tam, stdin);
	msgU = msg;

	cout << msgU << endl;

	for (int i = 0; i < msgU.size(); i++)
	{
		for (int x = 5; x <= 20; x++)
		{   Sleep(900);
			gotoxy(50, 5);
			cout << msgU;
			gotoxy(col, x);
			cout << msgU.at(i);
			system("cls");
			gotoxy(50, 20);
			cout << msgU;

			if(x > 19)
			{
				col += y;
			}
		}
	}
	return 0;
}
