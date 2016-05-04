/* 输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1,2,3一直到最大的3位数即999 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void print_1_to_max_of_n_digit(int n)
{
	int max = 1;
	int i = 0;

	if (n <= 0)
		return;

	for (i = 0; i < n; i++)
	{
		max *= 10;
	}

	for (i = 1; i < max; i++)
	{
		printf("%d\t", i);
	}

}


*/

void print_num(char *data, int len)
{
	int i = 0;
	int flag = 0;

	while ('0' == data[i])
	{
		i++;
	}
	
	printf("%s\t", data + i);
	if (0 == flag)
	{
		flag = 1;
		if (0 == strcmp("0", data))
			return;
	}
	printf("\t");
}

void permutation(char *num, int len, int index)		//index传进来的下标是当前待设置的下标
{
	int i = 0;
	
	if (len == index)				//num[len]已经越界，之前位都已设置，可以打印
	{
		print_num(num, len);
		return;
	}

	for (i = 0; i < 10; i++)
	{
		num[index] = i + '0';
		permutation(num, len, index + 1);	
	}

}

void print_1_to_max_of_n_digits(int n)
{
	char *number = (char *)malloc((n + 1) * sizeof(char));
	
	if (n <= 0)
		return;

	number[n] = '\0';

	permutation(number, n, 0);
	printf("\n");

	free(number);
	number = NULL;
}

int main()
{

	print_1_to_max_of_n_digits(3);


	return 0;
}
