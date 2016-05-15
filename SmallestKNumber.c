/* 输入n个整数，找出其中最小的k个数 */

#include <stdio.h>

void Swap(int *e1, int *e2)
{
	int tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

int Media_3(int arr[], int start, int end)
{
	//返回头中尾三个数的中位数的下标

	int mid = (end - start) / 2 + start;

	if (arr[start] > arr[mid])
		Swap(&arr[start], &arr[mid]);
	if (arr[start] > arr[end])
		Swap(&arr[start], &arr[end]);
	if (arr[mid] > arr[end])
		Swap(&arr[mid], &arr[end]);

	return mid;
}

int partition(int arr[], int len, int start, int end)
{
	int small, index;

	if (NULL == arr || len <= 0 || start < 0 || end >= len)
		return -1;
	
	index = Media_3(arr, start, end);
	Swap(&arr[index], &arr[end]);
	small = -1;
	for (index = start; index < end; ++index)
	{
		if (arr[index] < arr[end])
		{
			++small;
			if (index != small)
				Swap(&arr[index], &arr[small]);
		}
	}
	++small;
	Swap(&arr[small], &arr[end]);

	return small;
}

void SmallestKNumber(int input[], int n, int output[], int k)
{
	int index;
	int start = 0, end = n - 1;

	if (NULL == input || n <= 0 || NULL == output || k <= 0 || k >= n)
		return;
	
	index = partition(input, n, start, end);

	while (index != k - 1)
	{
		if (index < k - 1)
		{
			start = index + 1;
			index = partition(input, n, start, end);
		}
		else
		{
			end = index - 1;
			index = partition(input, n, start, end);
		}
	}
	
	for (index = 0; index < k; ++index)
		output[index] = input[index];
}


int main()
{
	int input[8] = {10, 9, 8, 7, 6, 0, 1, 3};
	int output[3];
	int i = 0;

	SmallestKNumber(input, 8, output, 3);

	for (i = 0; i < 3; ++i)
		printf("%d ", output[i]);
	printf("\n");

	return 0;
}
