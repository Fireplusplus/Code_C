#include <stdio.h>
#include <stdlib.h>

/* ÔÚÆÁÄ»ÉÏ´òÓ¡Ñî»ÔÈý½Ç */

int main(void)
{
	int a[10][10];
	int i = 0, j = 0, k = 0;

	for (i = 0; i < 10; i++) {
		a[i][0] = 1; 
		a[i][i] = 1;
	}
	for (i = 2; i < 10; i++) {
		for (j = 1; j<i; j++)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
	}
	for (i = 0; i < 10; i++) {
		for (k = 0; k < 10-1-i;k++) {
			printf(" ");
		}
		for (j = 0; j <= i; j++) {
			if (a[i][j] < 10)
				printf(" %d ", a[i][j]);
			else if (a[i][j] < 100)
				printf("%2d ", a[i][j]);
			else if (a[i][j] < 1000)
				printf("%3d ", a[i][j]);
		}	
		printf("\n");
	}
	

	system("pause");
	return 0;
}
