/* 二分查找 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define N 100

int dichotomy_search(int arr[], int x)
{
	int i = 0;
	int left = 0, right = N, mid = 0;
	
	while (left <= right) {
		mid = (right - left) / 2 + left;
		if (arr[mid] < x)
			left = mid + 1;
		else if (arr[mid] > x)
			right = mid - 1;
		else
			return mid;	
	}
	return -1;
}

int main(void)
{
	int arr[N] = {0};
	int i = 0, ret = 0, x = 0;

	//初始数组非递减排列
	for (i = 0; i < N; i++) {
		arr[i] = i;
	}
	while (scanf("%d", &x) != EOF) {
		ret = dichotomy_search(arr, x);
		if (ret >= 0)
			printf("%d\n", arr[ret]);
		else
			printf("not exist\n");
	}

	system("pause");
	return 0;
}
