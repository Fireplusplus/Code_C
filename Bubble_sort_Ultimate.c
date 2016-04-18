/* 实现bubble_sort,可以排序各种类型数据 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Swap(char *elem1, char *elem2, size_t width)
{
	int i = 0;
	char tmp = 0;

	for (i = 0; i <(int)width; i++)
	{
		tmp = *elem1;
		*elem1 = *elem2;
		*elem2 = tmp;
		elem1++;
		elem2++;
	}
}

void bubble_sort(void *base, size_t sz, size_t width, int (*cmp)(const void *, const void *))
{
	int i = 0, j = 0;

	for (i = 0; i < (int)sz - 1; i++)
	{	
		static int flag = 0;
		for (j = 0; j < (int)sz - i - 1; j++)
		{
			if (cmp(((char *)base + j*(int)width), ((char *)base + (j + 1)*(int)width)) > 0)
				Swap((char *)base + j*(int)width, (char *)base + (j + 1)*(int)width, width);
			flag = 1;
		}
		if (flag == 0)
			break;
	}

}

int Compare(const void *elem1, const void *elem2)
{
	return *(int *)elem1 - *(int *)elem2;
}

int main()
{
	int i = 0;
	int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
	int sz = sizeof(arr) / sizeof(arr[0]);


	bubble_sort(arr, sz, sizeof(int), Compare);

	for (i = 0; i < sz; i++)
	{
		printf("%d\n", arr[i]);
	}

	system("pause");
	return 0;
}