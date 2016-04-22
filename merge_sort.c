#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define N 1000

void merge(int elem[], int tmp[], int left, int right, int right_end)
{
	int i = 0;
	int left_end = right - 1;
	int t = left;
	int nums = right_end - left + 1;
	while (left <= left_end && right <= right_end) {
		if (elem[left] <= elem[right])
			tmp[t++] = elem[left++];
		else
			tmp[t++] = elem[right++];
	}
	while (left <= left_end)
		tmp[t++] = elem[left++];
	while (right <= right_end)
		tmp[t++] = elem[right++];
	for (i = 0; i < nums; i++, right_end--)
		elem[right_end] = tmp[right_end];	
}
void m_sort(int elem[], int tmp[], int left, int right_end)
{
	int center;
	if (left < right_end) {
		center = (right_end - left) / 2 + left;
		m_sort(elem, tmp, left, center);
		m_sort(elem, tmp, center + 1, right_end);
		merge(elem, tmp, left, center + 1, right_end);
	}
}
void merge_sort(int elem, int n)
{
	int *tmp = (int *)malloc(n * sizeof(int));
	if (tmp) {
		m_sort(elem, tmp, 0, n - 1);
		free(tmp);
	}
	else
		printf("¿Õ¼ä²»×ã!\n");
}
int main(void)
{
	int arr[N] = {0};
	int i = 0, j = 1000;

	for (i = 0; i < N; i++) {
		arr[i] = j--;
	}
	merge_sort(arr, N);
	for (i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}
