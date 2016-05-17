/* 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
 * 打印能拼接出的所有数字中最小的一个。*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_MAX_LEN 10

int cmp(const void* e1, const void *e2)
{
	char *a = *(char **)e1, *b = *(char **)e2;
	char ab[NUM_MAX_LEN * 2 + 1]= {0}; 
	char ba[NUM_MAX_LEN * 2 + 1]= {0}; 
	
	strcpy(ab, a);
	strcat(ab, b);

	strcpy(ba, b);
	strcat(ba, a);

	return strcmp(ab, ba);
}

void PrintMinNumber(int arr[], int n)
{
	int i = 0;
	char **str = (char **)malloc(n * sizeof(char *));

	if (NULL == arr || n <= 0)
		return;
	for (i = 0; i < n; i++)
	{
		str[i] = (char *)malloc(NUM_MAX_LEN + 1);
		sprintf(str[i], "%d", arr[i]);
	}
	
	qsort(str, n, sizeof(char *), cmp);

	for (i = 0; i < n; i++)
	{
		printf("%s", str[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		free(str[i]);
	}
	free(str);
}

int main()
{
	int arr[] = {3, 32, 321};

	PrintMinNumber(arr, 3);

	return 0;
}
