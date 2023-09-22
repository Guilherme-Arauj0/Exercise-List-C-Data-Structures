#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void bubbleSort(int vet[10], int  retorno){
	
	int x, y;
	
	for(x=0; x<9;x++){
		for(y=0; y< 9-x; y++){
			if(vet[y] > vet[y+1]){
				
				int aux = vet[y];
				vet[y] = vet[y+1];
				vet[y+1] = aux;
			}
		}
		
	}
	
}



int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int i, vet[10];
	
	srand(time(NULL));
		
	for(i=0;i<10;i++){
		vet[i] = rand() % 1000;		
	}
	
	printf("\nVETOR DESORDENADO: \n\n");
	
	for(i=0;i<10;i++){
		printf("%d\t ", vet[i]);
	}
	
	bubbleSort(vet, 10);
	
	printf("\n \n \nVETOR ORDENADO: \n\n");
	
	for(i=0;i<10;i++){
		printf(" %d\t", vet[i]);
	}
	
	
	return 0;
}
