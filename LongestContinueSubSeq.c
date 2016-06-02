/* 求数组中最长递增数列 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Len(int arr[], int n)
{
	int *tmp;
	int i, j;
	int max = 0;
	if (NULL == arr || n <= 0)
		return 0;
		
	tmp = (int *)calloc(n, sizeof(int));
	if (NULL == tmp)
		return 0;
	
	for (i = 0; i < n; i++)
	{
		tmp[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (arr[i] >= arr[j] && tmp[j] + 1 > tmp[i])
				tmp[i] = tmp[j] + 1;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (tmp[i] > max)
			max = tmp[i];
	}
	return max;
}

int Len2(int arr[], int n)
{
	int *tmp, size = 1;	//保存长度为index的最小末尾元素
	int i;
	if (NULL == arr || n <= 0)
		return 0;
	tmp = (int *)calloc(n + 1, sizeof(int));
	*tmp = INT_MAX;
	*(tmp + 1) = arr[0];
	for (i = 1; i < n; i++)
	{
		if (arr[i] > tmp[size])
		{
			size++;
			tmp[size] = arr[i];
		}
		else
		{
			int j = size - 1;
			while (arr[i] < tmp[j])
				j--;
			tmp[j+1] = arr[i];
		}
	}
	while (tmp[size] == 0)
		size--;
	free(tmp);
	return size;

}

int main()
{
	int arr[] = {1, 3, 5, 2, 4, 6, 7, 8};
	int ret = Len2(arr, 8);
	printf("%d\n", ret);

	return 0;
}
