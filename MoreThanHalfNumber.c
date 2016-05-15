#include <stdio.h>

enum
{
	VALID,
	INVALID
}state;

void Swap(int *e1, int *e2)
{
	int tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

int Media_3(int arr[], int start, int end)
{
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
	int pivot = 0;
	int small, index;
	if (NULL == arr || len <= 0 || start < 0 || end >= len)
		return -1;
	
	pivot = Media_3(arr, start, end);
	Swap(&arr[pivot], &arr[end]);
	small = start - 1;
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

void QuickSort(int data[], int len, int start, int end)
{
	int index;

	if (start == end)
		return;
	
	index = partition(data, len, start, end);
	if (index > start)
		QuickSort(data, len, start, index - 1);
	if (index < end)
		QuickSort(data, len, index + 1, end);
}

int CheckMoreThanHalf(int arr[], int len, int num)
{
	int i = 0;
	int cnt = 0;

	for (i; i < len; ++i)
	{
		if (arr[i] == num)
			++cnt;
	}
	if (cnt << 1 <= len)
		return 0;	//没有超过一半
	else
		return 1;
}

int MoreThanHalfNumber(int arr[], int len)
{
	int index = 0;
	int mid = len >> 1;
	int ret;
	int start = 0;
	int end = len - 1;

	state = INVALID;	//标识返回值是否有效
	if (NULL == arr || len <= 0)
		return 0;

	index = partition(arr, len, 0, len - 1);
	while (index != mid)
	{
		if (index > mid)
		{
			end = index - 1;
			index = partition(arr, len, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(arr, len, start, end);
		}
	}
	ret = arr[index];
	if (!CheckMoreThanHalf(arr, len, ret))
		ret = 0;
	else
		state = VALID;
	return ret;
}

int MoreThanHalfNumber_2(int arr[], int len)
{
	int ret, i;
	int cnt;
	state = INVALID;
	if (NULL == arr || len <= 0)
		return 0;

	ret = arr[0];
	cnt = 1;
	for (i = 1; i < len; i++)
	{
		if (0 == cnt)
		{
			ret = arr[i];
			cnt = 1;
		}
		else if (arr[i] == ret)
			++cnt;
		else
			--cnt;
	}
	
	if (!CheckMoreThanHalf(arr, len, ret))
		ret = 0;
	else
		state = VALID;

	return ret;
}

int main()
{
	int arr[10] = {1, 2, 2, 2, 3, 2, 3, 4, 2, 2};
	
	int ret = MoreThanHalfNumber_2(arr, 10);
	
	if (VALID == state)
		printf("%d\n", ret);
	else
		printf("not exist\n");
	return 0;
}
