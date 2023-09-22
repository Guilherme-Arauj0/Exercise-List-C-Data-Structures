#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>



void bubbleSort(char vet[10], int n){

 int x, y;
	 
	 for(x=0;x<9;x++){
	 	for(y=0;y<9;y++){
	 		if (vet[y] > vet[y+1]){
	 			
	 			char aux = vet[y];
	 			vet[y] = vet[y+1];
	 			vet[y+1] = aux;
			 }
		 }
	 } 

}


void quickSort(int *a, int left, int right){
	int i, j, x,y;
	
	i = left;
	j = right;
	x = a[(left + right) / 2];
	
	while(a[i] < x && i < right){
		i++;
	}
	while(a[j] > x && j > left){
		j--;
	}
	if(i <= j){
		y=a[i];
		a[i] = a[j];
		a[j] = y;
		i++;
		j--;
		
	}
	
	if(j > left){
		quickSort(a, left,j);
	}
	if(i< right){
		quickSort(a, i, right);
	}

}


void merge(int vet[], int left, int middle, int right) {
    int i, j, k;
    int x = middle - left + 1;
    int y = right - middle;

    int L[x], R[y];

    for (i = 0; i < x; i++)
        L[i] = vet[left + i];
    for (j = 0; j < y; j++)
        R[j] = vet[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < x && j < y) {
        if (L[i] <= R[j])
            vet[k++] = L[i++];
        else
            vet[k++] = R[j++];
    }

    while (i < x)
        vet[k++] = L[i++];

    while (j < y)
        vet[k++] = R[j++];
}

void mergeSort(int vet[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        int x = middle - left + 1;
        int y = right - middle;

        mergeSort(vet, left, middle);
        mergeSort(vet, middle + 1, right);

        merge(vet, left, middle, right);
    }
}


int main() {
	setlocale(LC_ALL, "");
	
	
	int vet2[20];
	char vet[10];
	int x;
	clock_t start, end; //clock_t is a variable type included in time.h librarie.
	double cpu_time_spended;

	
	printf("-----------------------------------------------Guilherme Araujo----------------------------------------------------\n\n");
	
	printf("\n\nThis is a code that call 3 functions: BubbleSort, QuickSort, MergeSort in random arrays and then show the time spent to execute them\n\n");

	//Array1
	srand(time(NULL));
	for(x=0; x<10; x++){
		vet[x] = rand() % 100;	
	}
	
	printf("\n -  The array number 1 and its random positions:\n\n");
	
	for(x=0;x<10;x++){
		printf("%d\t", vet[x]);
	}
	
	//	
	//							BUBBLE SORT:
	//	
	
	start = clock();
	
	bubbleSort(vet, 10);
	
	end = clock();
		
	cpu_time_spended = ((double)(start - end)) / CLOCKS_PER_SEC; // CLOCKS_PER_SEC is a constant already declared in time.h librarie.
		
	printf("\n\n Set ordered by method BubbleSort: \n\n");
		
	for(x=0;x<10; x++){
		printf("%d\t", vet[x]);
	}
		
	
	printf("\n \n Time taken to complete the method: %f \n\n", cpu_time_spended);
	
	printf("-------------------------------------------------------------------------------------------------------------------");
	
	//Array2
	srand(time(NULL));
	for(x=0; x<20; x++){
		vet2[x] = rand() % 100;	
	}
	
	printf("\n -  The array number 2 and its random positions:\n\n");
	
	for(x=0; x<20; x++){
		printf("%d\t", vet2[x]);
	}
		
	
//	
//								QUICK SORT:
//
	int o = sizeof(vet2) / sizeof(vet2[0]);
	
	start = clock();
	quickSort(vet2, 0, o - 1);
	end = clock();

	cpu_time_spended = ((double)(start - end)) / CLOCKS_PER_SEC;
	
	printf("\n\nSet ordered by method QuickSort:\n\n");
	
	for(x=0; x<20; x++){
		printf("%d\t", vet2[x]);
	}
	
	printf("\n \n Time taken to complete the method: %f \n\n", cpu_time_spended);
	
	printf("-------------------------------------------------------------------------------------------------------------------");
	
//	
//								MERGE SORT:
//
int vet3[10];

    srand(time(NULL));
    for (x = 0; x < 10; x++) {
        vet3[x] = rand() % 100;
    }

    printf("\n - The array number 3 and its random positions:\n\n");

    for (x = 0; x < 10; x++) {
        printf("%d\t", vet3[x]);
    }
	
	start = clock();
    mergeSort(vet3, 0, 9);
	end = clock();
	
	cpu_time_spended = ((double)(start - end)) / CLOCKS_PER_SEC;
	
    printf("\n\nSet ordered by method Merge Sort:\n\n");

    for (x = 0; x < 10; x++) {
        printf("%d\t", vet3[x]);
    }
    printf("\n\n Time taken to complete the method: %f \n\n", cpu_time_spended);
	printf("-------------------------------------------------------------------------------------------------------------------");
	
	return 0;
}

