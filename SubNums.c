/* n个数，两两组成二元组，差最小的有多少对，差最大的有多少对 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *e1, const void *e2)
{
	return *(int *)e1 - *(int *)e2;
}

void Nums(int arr[], int size, int *min, int *max)
{
	int i, tmp;
	int SubMin = 0;
	*min = 0;
	*max = 0;
	if (NULL == arr || size <= 1)
		return;
	
	qsort(arr, size, sizeof(int), cmp);
	SubMin = arr[1] - arr[0];
	for (i = 2; i < size; i++)
	{
		tmp = arr[i] - arr[i - 1];
		if (tmp == SubMin)
			(*min)++;
		else if (tmp < SubMin)
		{
			(*min) = 1;
			SubMin = tmp;
		}
	}
	if (arr[0] == arr[size - 1])
	{
		i = size;
		while (--i)
			(*max) += i;
	}
	else
	{
		int min_nums = 1, max_nums = 1;
		int num_min = arr[0], num_max = arr[size - 1];
		for (i = 1; i < size && arr[i] == num_min; ++i)
			min_nums++;

		for (i = size - 2; i >= 0 && arr[i] == num_max; --i)
			max_nums++;
		*max = min_nums * max_nums;
	}
}

int main()
{
	int arr[] = {45, 12, 45, 32, 5, 6};
	int max, min;
	Nums(arr, 6, &min, &max);
	printf("min nums: %d max nums: %d\n", min, max);

	return 0;
}
