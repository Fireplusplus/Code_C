#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define N 1000

void insert_sort(int *a, int num)
{
	int tmp = 0;
	int i = 0, j = 0;

	for (i = 1; i < num; i++) {
		tmp = a[i];
		j = i - 1;
		while ((tmp<a[j]) && (j >= 0)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;	
	}
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int find_median(int *a, int left, int right)
{/* 取头中尾的中位数作为主元 */
	int mid = (right - left) / 2 + left;

	if (a[left] > a[mid]) 
		swap(&a[left], &a[mid]);
	if (a[left] > a[right])
		swap(&a[left], &a[right]);
	if (a[mid] > a[right])
		swap(&a[mid], &a[right]);
	swap(&a[mid], &a[right - 1]);
	return a[right - 1];
}

void quick_sort(int *a, int left, int right)
{
	int pivot, cutoff, l, r;
	cutoff = 100;
	
	if (cutoff < right - left) {
		pivot = find_median(a, left, right);
		l = left;
		r = right - 1;
		while (1) {
			while (a[++l] < pivot);
			while (a[--r] > pivot);
			if (l < r)
				swap(&a[l], &a[r]);
			else
				break;
		}
		swap(&a[l], &a[right - 1]);
		quick_sort(a, left, l - 1);
		quick_sort(a, l + 1, right);
	}
	else
		insert_sort(a + left, right - left + 1);
}

int main(void)
{
	int arr[N] = { 0 };
	int i = 0, data = 1000;

	/*初始化待排数组*/
	for (i = 0; i < N; i++){
		arr[i] = data--;
	}

	/*调用统一接口*/
	quick_sort(arr, 0, N-1);

	/*打印到屏幕*/
	for (i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}