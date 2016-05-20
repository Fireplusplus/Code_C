/* 查找数字在排序数组中出现的次数 */
#include <stdio.h>

int BinarySearch(int *arr, int len, int k)
{
	int start = 0, end = len - 1;
	
	if (NULL == arr || len <= 0)
		return -1;
	
	while (start <= end)
	{
		int mid = (end - start) / 2 + start;
		if (arr[mid] == k)
			return mid;
		else if (arr[mid] < k)
			start = mid + 1;
		else
			end = mid - 1;
	}
}

int TimesOfNumInSortArray(int *arr, int size, int k)
{
	int left, right;
	
	if (NULL == arr)
		return -1;
	left = BinarySearch(arr, size, k);	
	right = left;
	while (left > 0 && arr[left - 1] == k)
	{	
		left = BinarySearch(arr, left, k);	
	}
	while (right < size - 1 && arr[right + 1] == k)
	{	
		right = BinarySearch(arr + right, size - right - 1, k);	
	}
	
	return right - left + 1;
}


int main()
{
	int arr[] = {1, 2, 2, 2, 3, 4, 5};

	int ret = TimesOfNumInSortArray(arr, 7, 2);
	printf("%d\n", ret);
	

	return 0;
}
