/*
#include <stdio.h>
#include <stdlib.h>

void get_array(int array[],int x);
void print_array(int a[], int x);
void primearray(int a[] , int x);


int main() {

	int x;
	
	printf("您想查看多少以内的数？\n");
	scanf_s("%d", &x);
	int* array = (int*)malloc(x * sizeof(int));
	
	
	get_array(array,x);
	
	primearray(array, x);
	
	printf("\n以下为素数表：\n");
	
	print_array(array, x);
	
	free(array);
	return 0;
}

void get_array(int array[],int x) {
	
	int i,j;
	
	for (i = 0; i < x; i++) {

		j = i + 1;
		array[i] = j;
	}

}

void print_array(int a[], int x) {

	for (int i = 0; i < x; i++) {

		if (a[i] != 0) {
			printf("%d\t ", a[i]);

			if ((i + 1) % 10 == 0) printf("\n");
		}
	}

}

void primearray(int a[], int x) {
	int j = 2;
	int ele = 2;
	a[0] = 0;

	for (int i = 1; i < x; i++) {
		j = 2;
		
		if (a[i] != 0) {
			ele = a[i];
			
			while (j * ele <= x) {

				a[j * ele - 1] = 0;
				j++;

			}
		}
	}
}
*/	