#include <stdio.h>
#include <iostream>
#include<stdlib.h>
#include <ctime>
#include <string>

int main(){
  
  std::string naipe[4] = {"Copas","Paus","Ouros","Espadas" };
   
  srand(time(NULL));
  int cartas[10][3];

  

  for(int a = 0; a < 4; a++){
    for(int b = 0; b < 13; b++){
      cartas[a][b] = rand() % 13 + 1;
      
    }
  }
  for (int l = 0; l < 4; l++) {
    printf("%iº jogador\n", l+1);
			    for (int c = 0; c < 11; c++){
    				printf("\n%i - ", cartas[l][c]);
            int a = rand() % 4;
            std::cout << naipe[a] + " - ";
            printf("%i\n", rand() % 2 + 1);
				}
    printf("------------------------------\n");
	}
  return 0;
}