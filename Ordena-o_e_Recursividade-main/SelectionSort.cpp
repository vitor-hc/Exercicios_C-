#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



void selecao(int vetor[], int n)
{

	int aux;
	for(int i = 0; i < n - 1; i++)
	{
		

		for(int j = i + 1; j < n; j++)
		{cout<<"["<<j<<"]: "<<vetor[j]<<", ["<<j+1<<"] : "<<vetor[j]<<endl;

		
			if(vetor[i]>vetor[j] )
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}






		}


	}


}
void print (int t , int *a){
	for(int i = 0; i < t; i++)
	{
		cout << "Elemento:"<<a[i] << endl;
		
	}
	cout << "-----------------" << endl;
}


int main(int argc, char** argv)
{

	int vetor[10] = {3, 0, 1, 8, 7, 2, 5, 4, 9,6};


	cout << "Selection Sort" << endl;
	selecao(vetor,10);
	print(10,vetor);
	


	return 0;
}
