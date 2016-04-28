#include <stdio.h>
#include <stdlib.h>

void swap(int *elem1, int *elem2)
{
	int tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

int partition(int data[], int len, int start, int end)
{
	/* 
	 * 主元选取方法：取首尾间的随机值或
	 * 取头中尾(或着五个数，七个数)的中位数
	 */
	int index = (end - start) / 2 + start;
	int i = 0, small = 0;
	
	if (NULL == data || len <= 0 || start < 0 || end >= len)
		exit(0);
	if (len <= 0)
	swap(&data[index], &data[end]);

	small = start - 1;
	for (index = start; index < end; index++)
	{
		if (data[index] < data[end])
		{
			small++;
			if (small != index)
				swap(&data[index], &data[small]);
		}
	}
	small++;
	swap(&data[small], &data[end]);

	return small;
}

void quick_sort(int data[], int len, int start, int end)
{
	int index = 0;
	if (start == end)
		return;
	
	index = partition(data, len, start, end);
	if (index > start)
		quick_sort(data, len, start, index - 1);
	if (index < end)
		quick_sort(data, len, index + 1, end);

}

int main()
{
	int arr[100];
	int i = 0;
	for (i = 0; i < 100; i++)
		arr[i] = 100 - i;

	quick_sort(arr, 100, 0, 99);

	for (i = 0; i < 100; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
